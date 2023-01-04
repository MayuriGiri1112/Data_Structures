//Maximum Area Histogram

#include<bits/stdc++.h>
using namespace std;

int MAH(int arr[], int size)
{
	vector<int> left, right;
	stack<pair<int, int> > s, s1;
	
	s.push(make_pair(arr[0], 0));
	s1.push(make_pair(arr[0], 0));
	
	//NSL index
	
	for(int i=0; i<size; i++)
	{
		if(s.size()==0)
		{
			left.push_back(-1);
		}
		else if(s.size()>0 && s.top().first<arr[i])
		{
			left.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first>=arr[i])
		{
			while(s.size()>0 && s.top().first>=arr[i])
			{
				s.pop();
			}
			if(s.size()==0)
			{
				left.push_back(-1);
			}
			else
			{
				left.push_back(s.top().second);
			}
		}
		s.push(make_pair(arr[i], i));
	}
	
	cout<<"\nLeft : ";
	for(int i=0; i<size; i++)
	{
		cout<<left[i]<<" ";
	}
	
	//NSR index
	
	for(int i=size-1; i>=0; i--)
	{
		if(s1.size()==0)
		{
			right.push_back(7);
		}
		else if(s1.size()>0 && s1.top().first<arr[i])
		{
			right.push_back(s1.top().second);
		}
		else if(s1.size()>0 && s1.top().first>=arr[i])
		{
			while(s1.size()>0 && s1.top().first>=arr[i])
			{
				s1.pop();
			}
			if(s1.size()==0)
			{
				right.push_back(7);
			}
			else
			{
				right.push_back(s1.top().second);
			}
		}
		s1.push(make_pair(arr[i], i));
	}
	
	reverse(right.begin(), right.end());
	
	cout<<"\nRight : ";
	for(int i=0; i<size; i++)
	{
		cout<<right[i]<<" ";
	}
	
	int width[10], area[10];
	
	for(int i=0; i<size; i++)
	{
		width[i] = right[i] - left[i] - 1;
	}
	
	cout<<"\nWidth : ";
	for(int i=0; i<size; i++)
	{
		cout<<width[i]<<" ";
	}
	
	for(int i=0; i<size; i++)
	{
		area[i] = arr[i] * width[i];
	}
	
	cout<<"\nArea : ";
	for(int i=0; i<size; i++)
	{
		cout<<area[i]<<" ";
	}
	
	int max = area[0];
	
	for(int i=0; i<size; i++)
	{
		if(max < area[i])
		{
			max = area[i];
		}
	}
	
	cout<<"\nMaximum Area of Histogram is "<<max;
	
	return 0;
}

int main()
{
	int arr[10], n;
	cout<<"\nEnter the length of array : ";
	cin>>n;
	cout<<"\nEnter elements in array : ";
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	MAH(arr, n);
	return 0;
}


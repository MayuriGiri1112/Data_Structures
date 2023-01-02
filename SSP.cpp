//Stock Spain Problem

#include<bits/stdc++.h>
using namespace std;

int StockSpain(int arr[], int size)
{
	vector<int> v;
	stack<pair<int, int> > s;
	
	s.push(make_pair(arr[0], 0));
	
	for (int i = 1; i < size; i++) 
	{
        if (s.empty()) 
		{
            s.push(make_pair(arr[i], i));
            continue;
        }
	}
	
	for(int i=0; i<size; i++)
	{
		if(s.size()==0)
		{
			v.push_back(-1);
		}
		else if(s.size()>0 && s.top().first>arr[i])
		{
			v.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first<=arr[i])
		{
			while(s.size()>0 && s.top().first<=arr[i])
			{
				s.pop();
			}
			if(s.size()==0)
			{
				v.push_back(-1);
			}
			else
			{
				v.push_back(s.top().second);
			}
		}
		s.push({arr[i], i});
	}
	
	for(int i=0; i<v.size(); i++)
	{
		v[i] = i - v[i];
	}
	
	for(int i=0; i<size; i++)
	{
		cout<<v[i]<<" ";
	}
	
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
	StockSpain(arr, n);
	return 0;
}

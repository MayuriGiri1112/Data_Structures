//Nearest Greater to Left

#include<bits/stdc++.h>
using namespace std;

int NGL(int arr[], int size)
{
	vector<int> v;
	stack<int> s;
	
	s.push(arr[0]);
	
	for (int i = 1; i < size; i++) 
	{
        if (s.empty()) 
		{
            s.push(arr[i]);
            continue;
        }
	}
	
	for(int i=0; i<size; i++)
	{
		if(s.size()==0)
		{
			v.push_back(-1);
		}
		else if(s.size()>0 && s.top()>arr[i])
		{
			v.push_back(s.top());
		}
		else if(s.size()>0 && s.top()<=arr[i])
		{
			while(s.size()>0 && s.top()<=arr[i])
			{
				s.pop();
			}
			if(s.size()==0)
			{
				v.push_back(-1);
			}
			else
			{
				v.push_back(s.top());
			}
		}
		s.push(arr[i]);
	}
	
	for(int i=0; i<size; i++)
	{
		cout<<v.at(i)<<" ";
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
	NGL(arr, n);
	return 0;
}

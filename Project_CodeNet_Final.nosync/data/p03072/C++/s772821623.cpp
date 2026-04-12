#include "stdio.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[100];
	int n;
	int count=1;
	int flag;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		flag=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]>a[i]) flag=0;
		}
		if(flag==1) count++;
	}
	cout<<count;
	return 0;
}
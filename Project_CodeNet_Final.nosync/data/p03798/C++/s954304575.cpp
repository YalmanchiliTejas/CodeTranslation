#include <bits/stdc++.h>
using namespace std;
int n,a[1000005];
int k1[4]={1,1,0,0},k2[4]={1,0,0,1};
char s[1000005];
bool check(int x,int y,int n)
{
	a[0]=x;
	a[1]=y;
	for(int i=1;i<n-1;i++)
	{
		if(s[i]=='o')
		{
			if(a[i])
				a[i+1]=a[i-1];
			else
				a[i+1]=!a[i-1];
		}
		else
		{
			if(a[i])
				a[i+1]=!a[i-1];
			else
				a[i+1]=a[i-1];
		}
	}
	if(s[0]=='o')
	{
		if(a[0])
		{
			if(a[1]!=a[n-1])
				return 0;
		}
		else if(a[1]==a[n-1])
			return 0;
	}
	else
	{
		if(a[0])
		{
			if(a[1]==a[n-1])
				return 0;
		}
		else if(a[1]!=a[n-1])
			return 0;
	}
	if(s[n-1]=='o')
	{
		if(a[n-1])
		{
			if(a[0]!=a[n-2])
				return 0;
		}
		else if(a[0]==a[n-2])
			return 0;
	}
	else
	{
		if(a[n-1])
		{
			if(a[0]==a[n-2])
				return 0;
		}
		else if(a[0]!=a[n-2])
			return 0;
	}
	return 1;
}
int main()
{
	cin>>n>>s;
	for(int i=0;i<4;i++)
	{
		if(check(k1[i],k2[i],n))
		{
			for(int j=0;j<n;j++)
			{
				if(a[j])
					cout<<"S";
				else
					cout<<"W";
			}
			return 0;
		}
	}
	cout<<"-1";

	return 0;
}
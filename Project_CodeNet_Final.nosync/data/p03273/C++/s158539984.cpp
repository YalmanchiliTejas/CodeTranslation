#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
bool flag;
char a[105][105];
bool u[105][105];
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>(a[i]+1);
	for(i=1;i<=n;i++)
	{
		flag=false;
		for(j=1;j<=m;j++)
			if(a[i][j]=='#')
			{
				flag=true;
				break;
			}
		if(!flag)
		{
			for(j=1;j<=m;j++)
				u[i][j]=true;
		}
	}
	
	for(j=1;j<=m;j++)
	{
		flag=false;
		for(i=1;i<=n;i++)
			if(!u[i][j]&&a[i][j]=='#')
			{
				flag=true;
				break;
			}
		if(!flag)
		{
			for(i=1;i<=n;i++)
				u[i][j]=true;
		}
	}
	for(i=1;i<=n;i++)
	{
		flag=false;
		for(j=1;j<=m;j++)
			if(!u[i][j])
			{
				cout<<a[i][j];
				flag=true;
			}
		if(flag) cout<<endl;
	}
	return 0;	
} 


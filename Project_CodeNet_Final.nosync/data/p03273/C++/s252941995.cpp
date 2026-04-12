#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s;
	int m,n,t;
	cin>>m>>n;
	int a[m][n],b[m]={0};
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>s;
			if(s=='#') a[i][j]=0;
			else a[i][j]=1;
		}
	}
	for(int i=0;i<m;i++)
	{
		t=0;
		for(int j=0;j<n;j++)
		{if(a[i][j]==1) t++;}
		if(t==n)
		{
			for(int j=0;j<n;j++)
			{a[i][j]=2;}
			b[i]=1;
		}
	}
	for(int j=0;j<n;j++)
	{
		t=0;
		for(int i=0;i<m;i++)
		{if(a[i][j]==1||a[i][j]==2) t++;}
		if(t==m)
		{
			for(int i=0;i<m;i++)
			{a[i][j]=2;}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==0) cout<<"#";
			else if(a[i][j]==1) cout<<".";
		}
		if(b[i]==0) cout<<endl;
	}
	return 0;
}
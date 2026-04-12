#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	char c[m+1][n+1];
	int f[m+1][n+1];
	int i,j;
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			cin>>c[i][j];
			if (c[i][j]=='.')
			{
				f[i][j]=0;
			}
			else
			{
				f[i][j]=1;
			}
		}
	}
	bool flag;
	for (i=1;i<=m;i++)
	{
		flag=true;
		for (j=1;j<=n;j++)
		{
			if (f[i][j]==1)
			{
				flag=false;
			}
		}
		if (flag==true)
		{
			for (j=1;j<=n;j++)
			{
				f[i][j]=2;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		flag=true;
		for (j=1;j<=m;j++)
		{
			if (f[j][i]==1)
			{
				flag=false;
				break;
			}
		}
		if (flag==true)
		{
			for (j=1;j<=m;j++)
			{
				f[j][i]=2;
			}
		}
	}
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (f[i][j]==0)
			{
				cout<<'.';
			}
			else if (f[i][j]==1)
			{
				cout<<'#';
			}
		}
		flag=false;
		for (j=1;j<=n;j++)
		{
			if (f[i][j]!=2)
			{
				flag=true;
			}
		}
		if (flag==true) cout<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
char a[105][105]; 
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		bool ok=true;
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]=='#')
			{
				ok=false;
				break;
			}
		}
		if(ok==true)
		{
			for(int j=i+1;j<=m;j++)
			{
				for(int k=1;k<=n;k++)
				{
					a[j-1][k]=a[j][k];
				}
			}
			i--;
			m--;
		}
	}
///	cout<<m<<n<<endl;
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<a[i][j];
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=n;i++)
	{
		bool ok=true;
		for(int j=1;j<=m;j++)
		{
			if(a[j][i]=='#')
			{
				ok=false;
				break;
			}
		}
		if(ok==true)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=i+1;k<=n;k++)
				{
					a[j][k-1]=a[j][k];
				}
			}
			i--;
			n--;
		}
	}
//	cout<<m<<n<<endl;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j];
		}
		cout<<"\n";
	}
	return 0;
}

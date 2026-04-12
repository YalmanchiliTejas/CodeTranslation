#include<iostream>
#include<cmath>
using namespace std;
int c[105],d[105];
int main()
{
	int n,m;
	cin>>n>>m;
	char a[105][105];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	for(int i=0;i<n;i++)
		{
			int j;
			for( j=0;j<m;j++)
				if(a[i][j]=='#')
					break;
			if(j==m)
				c[i]=1;
		}
	for(int j=0;j<m;j++)
		{
			int i;
			for( i=0;i<n;i++)
				if(a[i][j]=='#')
					break;
			if(i==n)
			d[j]=1;
		}
	for(int i=0;i<n;i++)
		{
			if(c[i])
			continue;
			for(int j=0;j<m;j++)
			{
				if(d[j])
				continue;
				else 
				cout<<a[i][j];
			}
			cout<<endl;
		}
} 
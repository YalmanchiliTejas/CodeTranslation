#include<bits/stdc++.h>
using namespace std ;

int main()
{
	int n, m ;
	cin >> n >> m ;

	int b[n]={0} ;
	int c[m]={0} ;

	char a[n][m] ;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j] ;
		}
	}

	for(int i=0;i<n;i++)
	{
		int flag=0 ;
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='#')
				flag=1 ;
		}

		if(flag==0)
		{
			b[i]=1 ;
		}
	}

	for(int i=0;i<m;i++)
	{
		int flag=0 ;
		for(int j=0;j<n;j++)
		{
			if(a[j][i]=='#')
				flag=1 ;
		}

		if(flag==0)
		{
			c[i]=1 ;
		}
	}

	for(int i=0;i<n;i++)
	{
		if(b[i]==1)
		{
			continue ;
		}

		for(int j=0;j<m;j++)
		{
			if((b[i]==1)||(c[j]==1))
			{
				continue ;
			}

			else
			{
				cout << a[i][j] ;
			}
		}

		cout << endl ;
	}

	return 0 ;
}
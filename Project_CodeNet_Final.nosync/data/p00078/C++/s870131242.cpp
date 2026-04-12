#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(cin>>n,n) 
	{
		int f[n][n];
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				f[i][j]=-1;
			}
		}

		int x=n/2,y=n/2+1;
		f[y][x]=1;
		for(int i = 1; i < n*n; ++i)
		{
			++x; ++y;
			while(x<0||n<=x||n<=y||f[y][x]!=-1) 
			{
				if(x<0) x=n-1;
				else if(n<=x) x=0;
				else if(n<=y) y=0;
				else
				{
					--x; ++y;
				}
			}
			f[y][x]=i+1;
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				printf("%4d",f[i][j]);
			}
			cout<<endl;
		}
	}
  return 0;
}
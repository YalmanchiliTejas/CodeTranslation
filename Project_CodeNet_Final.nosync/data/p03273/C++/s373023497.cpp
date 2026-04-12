#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define N 110
int main()
{
	ios::sync_with_stdio(false);
	int H,W;
	char a[N][N];
	char b[N][N];
	while(cin>>H>>W)
	{
		memset(a,'0',sizeof(a));
		int i,j;
		for(i=1;i<=H;i++)
			for(j=1;j<=W;j++)
				cin>>a[i][j];
		for(i=1;i<=H;i++)
			for(j=1;j<=W;j++)
				if(a[i][j]!='.')
				{
					a[i][0]='1';
					break;
				}
		for(j=1;j<=W;j++)
			for(i=1;i<=H;i++)
				if(a[i][j]!='.')
				{
					a[0][j]='1';
					break;
				}
		for(i=1;i<=H;i++)
		{
			if(a[i][0]=='1')
			{
				for(j=1;j<=W;j++)
				{
					if(a[0][j]=='1')
					{
						cout<<a[i][j];
					}
				}	
				cout<<endl;
			}
		}
	}
	return 0;
}

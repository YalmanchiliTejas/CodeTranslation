#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int f[15][15];
int x,y;
int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if(n==0)break;
		memset(f,0,sizeof(f));
		x=(n+1)/2;y=(n-1)/2;
		f[x][y]=1;
		for(int i=2;i<=n*n;i++)
		{
			x+=1;
			y+=1;
			x%=n;
			y%=n;
			if(f[x][y]==0)
			{
				f[x][y]=i;
			}
			else
			{
				while(f[x][y]!=0)
				{
					x+=1;
					y-=1;
					x+=n;
					y+=n;
					x%=n;
					y%=n;
				}
				f[x][y]=i;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%4d",f[i][j]);
			}
			cout << endl;
		}
	}
	return 0;
}
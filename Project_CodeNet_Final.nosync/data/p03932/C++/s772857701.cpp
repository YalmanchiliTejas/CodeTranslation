#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#define SIZE 205

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int dp[2][SIZE][SIZE];
int A[SIZE][SIZE];

int main()
{
	int h,w;
	scanf("%d %d",&h,&w);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	int pos=0;
	memset(dp,-1,sizeof(dp));
	dp[pos][0][0]=A[0][0];
	for(int i=1;i<=h+w-2;i++)
	{
		pos^=1;
		memset(dp[pos],-1,sizeof(dp[pos]));
		for(int j=0;j<w;j++)
		{
			for(int k=0;k<w;k++)
			{
				if(dp[pos^1][j][k]==-1) continue;
				for(int x=j;x<=j+1;x++)
				{
					for(int y=k;y<=k+1;y++)
					{
						int s=i-x,t=i-y;
						if(s<0||s>=h||t<0||t>=h||x>=w||y>=w) continue;
						dp[pos][x][y]=max(dp[pos][x][y],dp[pos^1][j][k]+A[s][x]+(s==t?0:A[t][y]));
					}
				}
			}
		}
	}
	printf("%d\n",dp[pos][w-1][w-1]);
	return 0;
}

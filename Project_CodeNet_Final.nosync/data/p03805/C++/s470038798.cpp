#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
int N,M,G[10][10],s,t,dp[300][10],a=0;

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d%d",&s,&t);
		s--;t--;
		G[s][t]=G[t][s]=1;
	}
	dp[1][0]=1;
	for(int i=1;i<(1<<N);i++)
	{
		for(int p=0;p<N;p++)
		{
			if((i>>p&1))
			{
				for(int t=0;t<N;t++)
				{
					if(!(i>>t&1)&&G[p][t]==1)
					{
						dp[i|(1<<t)][t]+=dp[i][p];
					}
				}
			}
		}
	}
	for(int i=0;i<N;i++)a+=dp[(1<<N)-1][i];
	printf("%d\n",a);
	return 0;
}

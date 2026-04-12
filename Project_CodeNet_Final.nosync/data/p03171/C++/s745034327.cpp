#include<bits/stdc++.h>
using namespace std;

const int maxn=3010;
long long dp[maxn][maxn];
int t[maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	if(!(n&1))
		for(int i=1;i<n;i++)
			dp[i][i+1]=max(t[i],t[i+1])-min(t[i],t[i+1]);
	if(n&1)
		for(int i=1;i<=n;i++)
			dp[i][i]=t[i];
	for(int i=(n&1) ? 3 : 4; i<=n;i+=2)
		for(int j=1;(j+i-1)<=n;j++)
		{
			long long right=min(dp[j][j+i-3]+t[j+i-1]-t[j+i-2],dp[j+1][j+i-2]+t[j+i-1]-t[j]);
			long long left=min(dp[j+2][j+i-1]+t[j]-t[j+1],dp[j+1][j+i-2]+t[j]-t[j+i-1]);
			dp[j][j+i-1]=max(left,right);
		}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;(j+i-1)<=n;j++)
			printf("%lld ",dp[j][j+i-1]);
		printf("\n");
	}*/
	printf("%lld",dp[1][n]);
}
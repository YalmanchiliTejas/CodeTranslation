#include<bits/stdc++.h>
typedef long long ll;
const int maxn=2e5+9;
using namespace std;
int main()
{
	ll n,a[maxn]={0},ans;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	ll dp[maxn][3]={0},k=n/2;
	if(n&1)
	{
		for(int i=1;i<=k;i++)
		{
			dp[i][0]=dp[i-1][0]+a[i*2-1];
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])+a[i*2];
			dp[i][2]=max(dp[i-1][0],max(dp[i-1][2],dp[i-1][1]))+a[i*2+1];
		}
		ans=max(max(dp[k][0],dp[k][1]),dp[k][2]);	
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			dp[i][0]=dp[i-1][0]+a[i*2-1];
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])+a[i*2];
		}
		ans=max(dp[k][0],dp[k][1]);
	}
	printf("%lld\n",ans);
	
	
}
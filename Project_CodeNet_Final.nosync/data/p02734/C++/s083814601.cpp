#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
const int N=3010;
int n,s,a[N],ans,dp[2][N];
signed main()
{
	scanf("%lld%lld",&n,&s);
	for (int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	int cur=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>s) continue;
		if (a[i]==s)
		{
			ans=(ans+i*(n-i+1)%mod)%mod;
			continue;
		}
		ans=(ans+dp[cur^1][s-a[i]]*(n-i+1)%mod)%mod;
		for (int j=1;j<s-a[i];j++)
		  dp[cur][j+a[i]]=(dp[cur][j+a[i]]+dp[cur^1][j])%mod;	
		dp[cur][a[i]]=(dp[cur][a[i]]+i)%mod;
		cur^=1;
		for (int j=0;j<s;j++) dp[cur][j]=dp[cur^1][j];
	}
	printf("%lld\n",ans);
}
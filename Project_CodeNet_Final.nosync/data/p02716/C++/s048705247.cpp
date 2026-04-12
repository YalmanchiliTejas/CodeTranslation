#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2*1e5+100;
int n,a[N],dp[N],sum[N];
signed main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	for (int i=1;i<=n;i+=2) sum[i]=sum[i-2]+a[i];
	for (int i=2;i<=n;i++)
	{
		if (i&1) dp[i]=max(dp[i-2]+a[i],dp[i-1]);
		else dp[i]=max(dp[i-2]+a[i],sum[i-1]);
	}
	printf("%lld\n",dp[n]);
}
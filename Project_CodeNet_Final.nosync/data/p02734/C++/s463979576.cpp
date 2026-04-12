#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[3005],dp[3005],sum[3005];
int main()
{
	int n,s,ans=0;
	scanf("%d%d",&n,&s);
	dp[0]=1;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		for (int j=s;j>=a[i];j--)
		dp[j]=(dp[j]+dp[j-a[i]])%mod;
		for (int j=0;j<=s;j++)
		sum[j]=(sum[j]+dp[j])%mod;
	}
	for (int i=0;i<n;i++)
	{
		ans=(ans+sum[s])%mod;
		for (int j=a[i];j<=s;j++)
		sum[j]=(sum[j]-sum[j-a[i]]+mod)%mod;
		sum[0]--;
	}
	printf("%d",ans);
}
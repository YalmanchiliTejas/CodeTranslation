#include<bits/stdc++.h>
using namespace std;
int a[3010];long long dp[3010];
const int mod=998244353;
int main()
{
	int n,s;
	cin>>n>>s;
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
    long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=s-a[i];j>=0;j--)
			dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
		dp[a[i]]+=i;
		ans=(ans+dp[s])%mod;
	}
    printf("%lld\n",ans);
    return 0;
}
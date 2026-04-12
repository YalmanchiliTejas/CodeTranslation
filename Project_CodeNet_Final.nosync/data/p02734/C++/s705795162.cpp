#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll dp[3004]={0};
ll a[3005];
ll n,s;
int main()
{
	ll ans=0;
	scanf("%lld%lld",&n,&s);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=s-a[i];j>=0;j--)
		{
			dp[j+a[i]]+=dp[j];
			dp[j+a[i]]%=mod;
		}
		dp[a[i]]+=i;
		ans+=dp[s];
		ans%=mod;
	}
	printf("%lld",ans);
}
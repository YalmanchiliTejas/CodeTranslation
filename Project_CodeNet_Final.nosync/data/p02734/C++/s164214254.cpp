#include<bits/stdc++.h>
#define debug1 cout<<"?"<<endl;
#define debug2 cout<<"?"<<i<<endl;
typedef long long ll;
#define PII pair<ll,ll>
const int maxn=2e5+9;
const double pi=acos(-1);
const int mod=998244353;
const int INF=0x3f3f3f3f;
const double ep=1e-10;
using namespace std;
int main()
{
	ll n,s,i,j,a[maxn]={0};
	ll dp[maxn]={0},ans=0;
	//dp[i]表示和为的个数 
	scanf("%lld%lld",&n,&s);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
	{
		dp[0]++;
		for(j=s;j>=a[i];j--)
		{
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		ans=(ans+dp[s])%mod;
	}
	printf("%lld\n",ans);
}
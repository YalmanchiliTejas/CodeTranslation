#include<bits/stdc++.h>
#define debug1 cout<<"?"<<endl;
#define debug2 cout<<"?"<<i<<endl;
typedef long long ll;
#define PII pair<ll,ll>
const int maxn=3e3+9;
const double pi=acos(-1);
const int mod=998244353;
const int INF=0x3f3f3f3f;
const double ep=1e-10;
using namespace std;
int main()
{
	ll n,s,i,j,a[maxn]={0};
	ll dp[maxn][maxn]={1},ans=0;
	//dp[i][j]表示前i个数和为j的个数 
	scanf("%lld%lld",&n,&s);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=s;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(a[i]<=j)dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
		}
		ans=(ans+dp[i][s])%mod;
		dp[i][0]=dp[i-1][0]+1;
	}
	printf("%lld\n",ans);
}
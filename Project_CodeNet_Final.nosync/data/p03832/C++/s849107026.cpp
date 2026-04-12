#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define FILL(a,x) memset(a,x,sizeof(a))
#define foreach( gg,ii ) for( typeof(gg.begin()) ii=gg.begin();ii!=gg.end();ii++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sz(a) int((a).size())
#define N 1000010
#define MAX 30
#define mod 1000000007
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define all(a) a.begin(),a.end()
const ll INF = 1e18+1;

ll dp[1010][1010];
ll fac[1010],invfac[1010];

ll power(ll a, ll b, ll m)
{
	ll ans=1;
	while(b)
	{
		if (b%2) ans*=a;
		b/=2;
		a*=a;
		if (a>=m) a%=m;
		if (ans>=m) ans%=m;
	}
	return ans;
}

int main()
{
	fac[0]=1;
	invfac[0]=1;
	REPP(i,1,1010){
		fac[i]=(fac[i-1]*i)%mod;
		invfac[i]=power(fac[i],mod-2,mod);
	}
	ll n,a,b,c,d,x,y,ans=0;
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	dp[a-1][0]=1;
	REPP(i,a,b+1){
		REP(j,n+1){
			dp[i][j]+=dp[i-1][j];
			REPP(cnt,c,d+1){
				if (j<cnt*i) break;
				dp[i][j]+=(((dp[i-1][j-cnt*i]*power(invfac[i],cnt,mod))%mod)*invfac[cnt])%mod;
			}
			dp[i][j]%=mod;
		}
	}
	ans=(dp[b][n]*fac[n])%mod;
	printf("%lld\n",ans);
return 0;
}
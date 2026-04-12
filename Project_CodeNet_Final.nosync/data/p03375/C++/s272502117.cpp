#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=3000+10;
inline ll quick_pow(ll base,ll n,ll mod) {
	ll ans=1;
	while(n) {
		if(n&1ll)
			ans=ans*base%mod;
		base=base*base%mod;
		n>>=1;
	}
	return ans;
}
ll c[maxn][maxn];
ll g[maxn][maxn];
int main() {
	ll n,mod;
	scanf("%lld%lld",&n,&mod);
	for(int i=1; i<=n; i++) {  //求组合数
		c[i][0]=1;
		c[i][i]=1;
		for(int j=1; j<i; j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	for(int i=0; i<=n; i++) {   //求g[i][j]
		g[i][0]=1;
		for(int j=1; j<=i; j++)
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j+1)%mod)%mod;
	}
	ll ans=0;
	for(int i=0; i<=n; i++) {            //直接套公式
		ll k=c[n][i];
		if(i&1)
			k=(mod-k)%mod;
		ll kind=quick_pow(2,n-i,mod);
		ll x=quick_pow(2,n-i,mod-1);     //注意这里的模数
		x=quick_pow(2,x,mod);
		ll cnt=0,y=1;
		for(int j=0; j<=i; j++) {
			cnt=(cnt+(g[i][j]*y%mod))%mod;
			y=kind*y%mod;
		}
		ans=(ans+(k*cnt%mod*x%mod))%mod;
	}
	printf("%lld\n",ans);
	return 0;
}

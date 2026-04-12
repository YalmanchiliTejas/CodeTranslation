#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=3e3+10;
ll n,mod,c[maxn][maxn],s[maxn][maxn],ans;

inline ll fpow(ll a,ll n,ll mod) {
	ll res=1;
	for(; n; n>>=1,a=a*a%mod)
		if(n&1ll)
			res=res*a%mod;
	return res;
}

int main() {
	cin>>n>>mod;
	for(int i=0; i<maxn; ++i) {
		c[i][0]=1;
		for(int j=1; j<=i; ++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	for(int i=0; i<maxn; ++i) {
		s[i][0]=1;
		for(int j=1; j<=i; ++j)
			s[i][j]=(s[i-1][j-1]+s[i-1][j]*(j+1))%mod;
	}
	for(int i=0; i<=n; ++i) {
		ll k=c[n][i];
		if(i&1)
			k=(mod-k)%mod;
		ll cnt=0;
		ll kind=fpow(2,n-i,mod);
		ll x=fpow(2,n-i,mod-1);
		x=fpow(2,x,mod);
		for(ll j=0,y=1; j<=i; ++j) {
			cnt=(cnt+(s[i][j]*y%mod))%mod;
			y=kind*y%mod;
		}
		ans=(ans+(k*cnt%mod*x%mod))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
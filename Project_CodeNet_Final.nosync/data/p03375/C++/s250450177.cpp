#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN=3005;
int n,D;

ll qpow(ll x,ll k,ll mod) {
	ll ret=1;
	while(k) {
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}

ll g[MAXN][MAXN],fac[MAXN],inv[MAXN];
void first(int lim) {
	for(int i=0;i<=lim;i++) {
		g[i][0]=1;
		for(int j=1;j<=i;j++)
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j+1))%D;
	}
	
	fac[0]=inv[0]=1;
	for(int i=1;i<=lim;i++) fac[i]=fac[i-1]*i%D;
	inv[lim]=qpow(fac[lim],D-2,D);
	for(int i=lim-1;i;i--) inv[i]=inv[i+1]*(i+1)%D;
}

ll C(int x,int y,int mod) {
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
ll calc(int x) {
	ll ret=0;
	for(int i=0;i<=x;i++)
		ret=(ret+g[x][i]*qpow(2,(ll)(n-x)*i,D))%D;
	return ret*qpow(2,qpow(2,n-x,D-1),D)%D;
}

ll ans;
int main() {
	scanf("%d%d",&n,&D);
	first(n);
	ans=qpow(2,qpow(2,n,D-1),D);
	for(int i=1;i<=n;i++) {
		ll tmp=C(n,i,D)*calc(i)%D;
		if(i&1) ans=(ans-tmp)%D;
		else ans=(ans+tmp)%D;
	}
	printf("%lld\n",(ans+D)%D);
	return 0;
}
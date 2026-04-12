#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1005, mod = 1e9+7;

ll n, a, b, c, d, dt[N][N];
ll fac[N] = {1}, inv[N] = {1}, cmb[N][N] = {1};

ll calc (ll X, ll Y) {
	if(!Y) return 1;
	ll R = calc(X, Y/2);
	R = R * R % mod;
	if(Y&1) R = R * X % mod;
	return R;
}

int main()
{
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	for(ll i=1;i<=n;i++) {
		fac[i] = fac[i-1] * i % mod;
		inv[i] = calc(fac[i], mod-2);
		cmb[i][0] = 1;
		for(ll j=1;j<=i;j++) {
			cmb[i][j] = (cmb[i-1][j-1] + cmb[i-1][j]) % mod;
		}
	}
	dt[a-1][n] = 1;
	for(ll i=a;i<=b;i++) {
		for(ll j=0;j<=n;j++) {
			ll T = 1;
			dt[i][j] = dt[i-1][j];
			for(ll k=1;j+i*k<=n && k<=d;k++) {
				T = T * cmb[j+i*k][i] % mod;
				if(k < c) continue;
				dt[i][j] += dt[i-1][j+i*k] * T % mod * inv[k];
				dt[i][j] %= mod;
			}
		}
	}
	printf("%lld\n",dt[b][0]);
}

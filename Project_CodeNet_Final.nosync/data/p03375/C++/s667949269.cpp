#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3005;

ll n, mod;

ll st[N][N] = {1}, t[N] = {1}, tt[N] = {2}, fac[N] = {1}, fi[N] = {1};

ll calc (ll X, ll Y) {
	if(!Y) return 1;
	ll R = calc(X, Y/2);
	R = R * R % mod;
	if(Y&1) R = R * X % mod;
	return R;
}

ll comb (ll X, ll Y) {
	return fac[X] * fi[Y] % mod * fi[X-Y] % mod;
}

int main()
{
	scanf("%lld%lld",&n,&mod);
	for(ll i=1;i<=n;i++) {
		fac[i] = fac[i-1] * i % mod;
		fi[i] = calc(fac[i], mod-2);
		t[i] = t[i-1] * 2 % (mod-1);
		tt[i] = calc(2, t[i]);
	}
	for(ll i=1;i<=n;i++) for(ll j=1;j<=n;j++) {
		st[i][j] = (st[i-1][j-1] + st[i-1][j] * j) % mod;
	}
	ll ans = tt[n];
	for(ll i=n;i--;) {
		ll T = comb(n, i) * tt[i] % mod, S = 0, W = calc(2, i), C = 1;
		for(ll j=1;j<=n-i;j++) {
			S = (S + (j * C + C * W) % mod * st[n-i][j]) % mod;
			C = C * W % mod;
		}
		ans = (ans + T * S % mod * (mod+1-(n-i)%2*2)) % mod;
	}
	printf("%lld\n",ans);
}

#include <bits/stdc++.h>

typedef long long int int64;
int64 mod;
int64 qpow(int64 a,int b)
{
	int64 c = 1;
	for(int i = 30;i >= 0;--i) {
		c = c * c % mod;
		if(((b>>i)&1)==1) c = c * a % mod;
	}
	return c;
}
int64 f[3002][3002];
int64 pow2[3001];
int64 inv[3001],fac[3001],invfac[3001];
int64 choice(int a,int b)
{
	if(a < b || b < 0) return 0;
	return fac[a] * invfac[b] % mod * invfac[a-b] % mod;
}
int n;
int main()
{
	scanf("%d%lld",&n,&mod);
	f[0][0] = 1;
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j) {
			f[i][j] = (f[i-1][j-1] + f[i-1][j] * j) % mod;
		}
	}
	pow2[0] = 2;
	for(int i = 1;i <= n;++i) pow2[i] = (pow2[i-1]*pow2[i-1])%mod;
	fac[0] = fac[1] = invfac[0] = invfac[1] = inv[1] = 1;
	for(int i = 2;i <= n;++i) {
		fac[i] = (fac[i-1]*i)%mod;
		inv[i] = (mod-mod/i)*inv[mod%i]%mod;
		invfac[i] = (invfac[i-1]*inv[i])%mod;
	}
	int64 ans = 0;
	for(int i = 0;i <= n;++i) { // # of 0,1 toppings
		int64 coe = choice(n,i) * pow2[n-i] % mod;
		int64 val = 0;
		int64 w1 = 1, w2 = qpow(2,n-i);
		for(int j = 0;j <= i;++j) { // # of ramen with topping 1..i
			val += (f[i][j+1]*(j+1) + f[i][j]) % mod * w1 % mod;
			w1 = w1 * w2 % mod;
		}
		if(i % 2 == 1) coe = -coe;
		ans += coe * (val % mod) % mod;
	}
	ans %= mod;
	if(ans < 0) ans += mod;
	printf("%lld\n", ans);
}

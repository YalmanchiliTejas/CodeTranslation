#include "bits/stdc++.h"
using namespace std;
long long s[3005][3005];
long long c[3005][3005];
long long w[3005];
int n, mod;

long long modpow(int x, int p, int MOD) {
	if(p == 0) return 1;
	if(p & 1) return (modpow(x, p-1, MOD) * x) % MOD;
	long long mid = modpow(x, p >> 1, MOD);
	return (mid * mid) % MOD;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &mod);
	for(int i = 0; i <= n; i++) s[0][i] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			s[i][j] = s[i - 1][j - 1] + s[i][j - 1] * (i + 1);
			s[i][j] %= mod;
		}
	}
	for(int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			c[i][j] %= mod;
		}
	}
	for(int i = 0; i <= n; i++) {
		w[i] = 0;
		long long P = modpow(2, modpow(2, n - i, mod - 1), mod);
		long long Q = modpow(2, (n - i), mod);
		long long R = 1;
		for(int j = 0; j <= i; j++) {
			long long add = c[n][i];
			add *= (s[j][i] * R) % mod;
			add %= mod;
			add *= P;
			add %= mod;
			w[i] += add;
			w[i] %= mod;
			R *= Q;
			R %= mod;
		}	
	}  
	long long ans = 0;
	for(int i = 0; i <= n; i++) {
		if(i & 1) ans -= w[i];
		else ans += w[i];
		ans %= mod;
	}
	if(ans < 0) ans += mod;
	printf("%lld\n", ans);
	return 0;
}
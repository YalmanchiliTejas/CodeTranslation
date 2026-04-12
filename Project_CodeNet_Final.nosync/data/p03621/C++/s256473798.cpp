#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 10000 + 10;
const int mod = 998244353;

char a[maxn], b[maxn];
LL fac[maxn], ifac[maxn];

LL fpm(LL a, LL b) {
	LL res = 1;
	for(; b > 0; b >>= 1) {
		if(b & 1)
			res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

void init() {
	fac[0] = 1;
	for(int i = 1; i < maxn; ++i) fac[i] = fac[i-1] * i % mod;

	ifac[maxn-1] = fpm(fac[maxn-1], mod-2);
	for(int i = maxn-1; i >= 1; --i) ifac[i-1] = ifac[i] * i % mod;
}

LL dp[2][maxn], ans;
LL M(LL x) { return x > 0 ? x : 0; }
LL C(int n, int k) {
	return fac[n] * ifac[k] % mod * ifac[n-k] % mod;
}

int main() {
	init();
	scanf("%s%s", a, b);
	
	int len = strlen(a), k = 0, n = 0;
	for(int i = 0; i < len; ++i) {
		if(a[i] == '1') ++ n;
		if(a[i] == '1' && b[i] == '0') ++ k;
	}
	
	if(k == 0) {
		return printf("%lld\n", fac[n]*fac[n] % mod), 0;
	}
	
	dp[1][0] = 1;
	int cur = 0;
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= i && j <= k; ++j) {
			dp[cur][j] = 0;
			if(j) dp[cur][j] = dp[cur^1][j-1] * (k-j+1) % mod * (k-j+1) % mod;
			dp[cur][j] = (dp[cur][j] + M(n-k-i+1+j) * dp[cur^1][j] % mod * (k-j)) % mod;
		}
		//cerr << dp[cur][k] * C(n, i) % mod * fac[n-i] % mod * fac[n-i] % mod << endl;
		ans = (ans + dp[cur][k] * C(n, i) % mod * fac[n-i] % mod * fac[n-i] % mod) % mod;
		cur ^= 1;
	}
	printf("%lld\n", ans);
	return 0;
}
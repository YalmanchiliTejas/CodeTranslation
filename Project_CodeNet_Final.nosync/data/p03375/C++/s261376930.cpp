#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
LL dp[3010][3010];
LL comb[3010][3010];
LL mod_pow(LL a, LL b,LL mod) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		LL t = mod_pow(a, b / 2, mod);
		return (t*t) % mod;
	}
	return (a*mod_pow(a, b - 1, mod)) % mod;
}
LL f(int N,int k,LL mod) {
	LL ans = 0;
	LL a = mod_pow(2, N - k, mod);
	LL b = 1;
	for (int i = 0; i <= k; i++) {
		LL t = (dp[k][i] * b) % mod;
		(b *= a) %= mod;
		(ans += t) %= mod;
	}
	(ans *= mod_pow(2, mod_pow(2, N - k, mod - 1), mod)) %= mod;
	return ans;
}
int main() {
	int N, M;
	cin >> N >> M;
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			(dp[i][j] += dp[i - 1][j]) %= M;
			(dp[i][j] += dp[i - 1][j] * j) %= M;
			(dp[i][j] += dp[i - 1][j - 1]) %= M;
		}
	}
	comb[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			(comb[i][j] += comb[i - 1][j]) %= M;
			(comb[i][j] += comb[i - 1][j - 1]) %= M;
		}
	}
	LL ans = 0;
	LL minus = 0;
	for (int i = 0; i <= N; i++) {
		LL t = f(N, i, M);
		(t *= comb[N][i]) %= M;
		if (minus) (t *= M - 1) %= M;
		minus ^= 1;
		(ans += t) %= M;
	}
	cout << ans << endl;
}
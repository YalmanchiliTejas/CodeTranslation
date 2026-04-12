#include <iostream>
using namespace std;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long N, M, dp[3009][3009], nr[3009][3009], power[9000009];

void init() {
	dp[0][0] = 1;
	for (int i = 0; i <= 3000; i++) {
		for (int j = 0; j <= 3000; j++) {
			dp[i + 1][j] += dp[i][j] * (j + 1); dp[i + 1][j] %= M;
			dp[i + 1][j + 1] += dp[i][j]; dp[i + 1][j + 1] %= M;
		}
	}
	for (int i = 0; i <= 3000; i++) {
		for (int j = 0; j <= 3000; j++) {
			if (i == 0 || j == 0) nr[i][j] = 1;
			else nr[i][j] = (nr[i - 1][j] + nr[i][j - 1]) % M;
		}
	}
	power[0] = 1; for (int i = 1; i <= 9000000; i++) power[i] = (power[i - 1] * 2) % M;
}
long long Ramen(long long a, long long b) {
	return dp[a][b];
}
long long ncr(long long a, long long b) {
	if (b < 0 || a < b) return 0;
	return nr[a - b][b];
}
long long solve(long long p) {
	long long ret = 0, Free = modpow(2, N - p, M - 1);
	for (int i = 0; i <= p; i++) {
		long long D = Ramen(p, i);
		ret += (D*power[(N - p)*i]); ret %= M;
	}
	ret *= modpow(2, Free, M); ret %= M;
	return ret;
}

int main() {
	cin >> N >> M;
	init();
	long long ans = 0;
	for (int i = 0; i <= N; i++) {
		long long K = solve(i);
		long long L = ncr(N, i);
		if (i % 2 == 0) ans += K*L;
		else ans -= K*L;
		ans += M*M; ans %= M;
	}
	cout << ans << endl;
	return 0;
}
#include <iostream>
using namespace std;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 60; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}
long long Div(long long a, long long b, long long m) {
	return (a*modpow(b, m - 2, m)) % m;
}

long long inv[2009], mod = 1000000007;

void init() {
	for (int i = 1; i <= 2008; i++) inv[i] = Div(1, i, mod);
}

long long ncr(long long n, long long r) {
	if (r < 0 || n < r) return 0;
	long long ret = 1;
	for (long long i = n; i > n - r; i--) { ret *= (i%mod); ret %= mod; }
	for (long long i = r; i >= 1; i--) { ret *= inv[i]; ret %= mod; }
	return ret;
}

long long dp[2009][2009];

long long solve(long long N, long long D, long long LIM) {
	if (LIM == 0) {
		if (N == 0) return 1;
		return 0;
	}
	for (int i = 0; i <= N; i++) { for (int j = 0; j <= N; j++) dp[i][j] = 0; }
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		long long S = 0;
		for (int j = 1; j <= N; j++) {
			S += dp[i - 1][j - 1];
			dp[i][j] = S%mod;
			if (j - LIM >= 0) S -= dp[i - 1][j - LIM];
		}
	}
	long long sum = 0;
	for (int i = 0; i <= N; i++) sum += (ncr(D, i)*dp[i][N]) % mod;
	return sum%mod;
}

int main() {
	long long A, B, C; init();
	while (true) {
		cin >> A >> B >> C; if (A + B + C == 0) break;
		cout << solve(A, B, C - 1) << endl;
	}
	return 0;
}

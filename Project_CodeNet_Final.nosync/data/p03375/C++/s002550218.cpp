#include <iostream>
using namespace std;

long long N, mod, dp[3009][3009], nr[3009][3009], FinalAns;

void init() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || i == 0) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + 1LL * dp[i - 1][j] * (j + 1)) % mod;
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0 || j == 0) nr[i][j] = 1;
			else nr[i][j] = (nr[i - 1][j] + nr[i][j - 1]) % mod;
		}
	}
}

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	long long K = 31; if (b <= 2500000) K = 22;
	for (int i = 0; i < K; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long ncr(long long n, long long r) {
	return nr[n - r][r];
}

int main() {
	cin >> N >> mod;
	init();

	for (int i = 0; i <= N; i++) {
		long long A1 = modpow(2, modpow(2, i, mod - 1), mod);
		long long A2 = 0;
		for (int j = 0; j <= N - i; j++) {
			long long K1 = dp[N - i][j];
			long long K2 = modpow(2, 1LL * j * i, mod);
			A2 += K1 * K2; A2 %= mod;
		}
		long long ans = (A1 * A2 % mod) * ncr(N, i) % mod;
		if ((N - i) % 2 == 0) FinalAns += ans;
		else FinalAns -= ans;
	}
	FinalAns += 1000000000LL * mod; FinalAns %= mod;
	cout << FinalAns << endl;
	return 0;
}
#include <iostream>
using namespace std;

long long N, A, B, C, D, dp[1009][1009], nr[1009][1009], inv[1009], mod = 1000000007;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

void init() {
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (i == 0 || j == 0) nr[i][j] = 1;
			else nr[i][j] = (nr[i - 1][j] + nr[i][j - 1]) % mod;
		}
	}
	for (int i = 1; i <= 1000; i++) inv[i] = modpow(i, mod - 2, mod);
}

long long ncr(long long n, long long r) {
	if (n < r || r < 0) return 0;
	return nr[n - r][r];
}

int main() {
	init();
	cin >> N >> A >> B >> C >> D;
	dp[A][0] = 1;
	for (int i = A; i <= B; i++) {
		for (int j = 0; j <= N; j++) {
			if (dp[i][j] == 0) continue;
			dp[i + 1][j] += dp[i][j]; dp[i + 1][j] %= mod;

			int sum = j; long long V = 1;
			for (int k = 1; k <= D; k++) {
				sum += i; if (sum > N) break;
				V *= ncr(sum, sum - i); V %= mod;
				V *= inv[k]; V %= mod;
				if (C <= k) {
					dp[i + 1][sum] += dp[i][j] * V;
					dp[i + 1][sum] %= mod;
				}
			}
		}
	}
	cout << dp[B + 1][N] << endl;
	return 0;
}
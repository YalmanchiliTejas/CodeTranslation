#include <iostream>
using namespace std;

long long dp[2009][2009], inv[2009], N, A, B, C, D, ret[2009][2009], mod = 1000000007;

long long ncr(long long M,long long R) {
	return dp[M - R][R];
}

int main() {
	for (int i = 0; i < 2008; i++) {
		for (int j = 0; j < 2008; j++) {
			if (i == 0 || j == 0) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	for (int i = 1; i <= 2008; i++) {
		for (int j = 0; j < i; j++) {
			long long T = 1LL * mod*j + 1;
			if (T%i == 0) { inv[i] = T / i; break; }
		}
	}
	cin >> N >> A >> B >> C >> D;
	ret[1][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i < A || B < i) {
				ret[i + 1][j] += ret[i][j]; ret[i + 1][j] %= mod;
				continue;
			}
			ret[i + 1][j] += ret[i][j]; ret[i + 1][j] %= mod;
			long long F = ret[i][j], cnt = 0;
			for (int k = j + i; k <= N; k += i) {
				F *= ncr(k, i); F %= mod; cnt++; F *= inv[cnt]; F %= mod;
				if (cnt < C || D < cnt) continue;
				ret[i + 1][k] += F; ret[i + 1][k] %= mod;
			}
		}
	}
	cout << ret[N + 1][N] << endl;
	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
#define MOD 1000000007LL
long long dp[2100][2100];
long long modpow(long long p, long long q) {
	long long s[64], sum = 1; s[0] = p; for (int i = 1; i < 64; i++)s[i] = (s[i - 1] * s[i - 1]) % MOD;
	for (int i = 0; i < 63; i++) { if ((q / (1LL << i)) % 2 == 1) { sum *= s[i]; sum %= MOD; } }
	return sum;
}
long long ncr(long long p, long long q) {
	long long r1 = 1; for (long long i = p; i > p - q; i--) { r1 *= (i%MOD); r1 %= MOD; }
	long long r2 = 1; for (long long i = q; i >= 1; i--) { r2 *= (i%MOD); r2 %= MOD; }
	return (r1*modpow(r2, MOD - 2)) % MOD;
}
int main() {
	while (true) {
		for (int i = 0; i < 4410000; i++)dp[i / 2100][i % 2100] = 0;
		dp[0][0] = 1; long long n, d, x; cin >> n >> d >> x; if (n + d + x == 0)break; x--;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int L = j - x, R = j - 1; if (L < 0)L = 0;
				long long sum = dp[i - 1][R]; if (L > 0)sum -= dp[i - 1][L - 1];
				sum = (sum + MOD) % MOD; dp[i][j] = sum;
			}
			for (int j = 1; j <= n; j++) { dp[i][j] += dp[i][j - 1]; dp[i][j] %= MOD; }
		}
		long long cnt = 0; for (int i = 1; i <= min(n, d); i++) { cnt += ncr(d, i)*dp[i][n]; cnt %= MOD; }
		cout << cnt << endl;
	}
	return 0;
}
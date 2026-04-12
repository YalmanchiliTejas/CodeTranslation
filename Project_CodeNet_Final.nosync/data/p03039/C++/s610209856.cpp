#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 100, MOD = 1e9 + 7;

long long fac[N], inv[N];
long long n, m, k, ans;

long long sum(long long a, long long b) {
    return (a + b + MOD) % MOD;
}

long long mul(long long a, long long b) {
    return 1LL * a * b % MOD;
}

long long power(long long a, long long p) {
    long long res = 1;
    for (; p; p /= 2) {
	if (p % 2)
	    res = mul(res, a);
	a = mul(a, a);
    }
    return res;
}

long long C(long long k, long long n) {
    return 1LL * fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    fac[0] = 1;
    for (long long i = 1; i < N; i++)
	fac[i] = mul(fac[i - 1], i);
    for (long long i = 0; i < N; i++)
	inv[i] = power(fac[i], MOD - 2);
    cin >> n >> m >> k;
    long long dp[n + 10][m + 10] = {};
    for (long long i = 1; i <= m; i++)
	dp[1][i] = dp[1][i - 1] + i - 1;
    for (long long i = 2; i <= n; i++) {
	dp[i][1] = sum(sum(dp[i - 1][1], mul(i - 2, m)), m * (m + 1) / 2 % MOD);
	for (long long j = 2; j <= m; j++)
	    dp[i][j] = sum(dp[i][j - 1], sum(mul(j - 1, i), -mul(i - 1, m - j + 1)));
    }
    for (long long i = 1; i <= n; i++)
	for (long long j = 1; j <= m; j++)
	    ans = sum(ans, dp[i][j]);
    cout << mul(ans, C(k - 2, m * n - 2));
    return 0;
}

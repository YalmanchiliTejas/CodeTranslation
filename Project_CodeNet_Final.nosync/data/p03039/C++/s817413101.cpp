#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 100, MOD = 1e9 + 7;

int fac[N], inv[N];
int n, m, k, ans;

int sum(int a, int b) {
    return (a + b + MOD) % MOD;
}

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

int power(int a, int p) {
    int res = 1;
    for (; p; p /= 2) {
	if (p % 2)
	    res = mul(res, a);
	a = mul(a, a);
    }
    return res;
}

int C(int k, int n) {
    return 1LL * fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i < N; i++)
	fac[i] = mul(fac[i - 1], i);
    for (int i = 0; i < N; i++)
	inv[i] = power(fac[i], MOD - 2);
    cin >> n >> m >> k;
    int dp[n + 10][m + 10] = {};
    for (int i = 1; i <= m; i++)
	dp[1][i] = dp[1][i - 1] + i - 1;
    for (int i = 2; i <= n; i++) {
	dp[i][1] = sum(sum(dp[i - 1][1], mul(i - 2, m)), m * (m + 1) / 2 % MOD);
	for (int j = 2; j <= m; j++)
	    dp[i][j] = sum(dp[i][j - 1], sum(mul(j - 1, i), -mul(i - 1, m - j + 1)));
    }
    for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	    ans = sum(ans, dp[i][j]);
    return cout << mul(ans, C(k - 2, m * n - 2)), 0;
}
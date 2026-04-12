#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3e3 + 5, inf = 1e18 + 123;
int n, a[N], dp[2][N][N];

int solve (bool _, int l, int r) {
    if (l > r) return 0;
    if (dp[_][l][r] != inf) return dp[_][l][r];
    if (!_) {
        dp[_][l][r] = max(solve(_ ^ 1, l, r - 1) + a[r], solve(_ ^ 1, l + 1, r) + a[l]);
    }
    else {
        dp[_][l][r] = min(solve(_ ^ 1, l, r - 1) - a[r], solve(_ ^ 1, l + 1, r) - a[l]);
    }
    return dp[_][l][r];
}

int32_t main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);

    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) dp[0][i][j] = dp[1][i][j] = inf;

    cout << solve(0, 1, n);

    return 0;
}

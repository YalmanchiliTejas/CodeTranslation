/*
 *  Lang    : C++
 *  Author  : little_angel
 */
#include <bits/stdc++.h>

using namespace std;
#define int long long

int dp[3001][3001], a[3001];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    for (int i = 0; i < n; ++i)dp[i][i] = a[i];
    for (int i = 0; i < n - 1; ++i)dp[i][i + 1] = max(a[i], a[i + 1]);
    for (int k = 2; k < n; ++k)
        for (int i = 0, j = k; j < n; ++i, ++j)
            dp[i][j] = max(a[i] + min(dp[i + 1][j - 1], dp[i + 2][j]), a[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
    cout << dp[0][n - 1] * 2 - sum << endl;
}
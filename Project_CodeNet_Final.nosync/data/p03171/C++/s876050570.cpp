/*
 *  Lang    : C++
 *  Author  : little_angel
 */
#include <bits/stdc++.h>

using namespace std;
#define int long long

int dp[3001][3001], a[3001];

int dfs(int i, int j) {
    if (i > j)return 0;
    if (dp[i][j])return dp[i][j];
    if (i == j)return dp[i][j] = a[i];
    if (i == j + 1)return dp[i][j] = max(a[i], a[j]);
    return dp[i][j] = max(a[i] + min(dfs(i + 1, j - 1), dfs(i + 2, j)), a[j] + min(dfs(i + 1, j - 1), dfs(i, j - 2)));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    cout << dfs(0, n - 1) * 2 - sum << endl;
}
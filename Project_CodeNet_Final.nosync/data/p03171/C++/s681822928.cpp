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

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int l = n - 1; l >= 0; --l) {
        dp[l][l] = a[l];
        for (int r = l + 1; r < n; ++r)dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
    }
    cout << dp[0][n - 1] << endl;
}
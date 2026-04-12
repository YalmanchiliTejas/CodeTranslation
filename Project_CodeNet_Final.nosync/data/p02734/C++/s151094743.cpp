#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define int long long
//#define ll long long
//#define double long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const int INF = 2e9;
const int MB = 20;
const int MOD = 998244353;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(s + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] < 0) continue;
            if (j - a[i] == 0) dp[i][j] += dp[i - 1][j - a[i]] + i;
            else dp[i][j] += dp[i - 1][j - a[i]];
            dp[i][j] %= MOD;
        }
        ans = (ans + dp[i][s]) % MOD;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(12);
    cout << fixed;
    solve();
}
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

void solve() {
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int dp[n][s + 1][3];
    for (int i = 0; i < n; ++i) for (int j = 0; j <= s; ++j) for (int k = 0; k < 3; ++k) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    dp[0][0][2] = 1;
    if (a[0] <= s) dp[0][a[0]][1] = 1;
    if (a[0] == s) dp[0][s][2] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= s; ++j) dp[i][j][0] = dp[i - 1][j][0];
        for (int j = 0; j <= s; ++j) dp[i][j][1] = (dp[i - 1][j][1] + dp[i - 1][j][0]) % mod;
        for (int j = 0; j <= s; ++j) dp[i][j][2] = (dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j][0]) % mod;
        for (int j = 0; j + a[i] <= s; ++j) {
            dp[i][j + a[i]][1] = (dp[i][j + a[i]][1] + dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
            dp[i][j + a[i]][2] = (dp[i][j + a[i]][2] + dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
        }
    }
    cout << dp[n - 1][s][2];
    /*vector <vector <int> > dp(n, vector <int> (s + 1));
    vector <vector <int> > pr(n, vector <int> (s + 1));
    dp[0][0] = 1;
    if (a[0] <= s) dp[0][a[0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= s; ++j) dp[i][j] = dp[i - 1][j];
        for (int j = 0; j <= s - a[i]; ++j) dp[i][j + a[i]] = (dp[i][j + a[i]] + dp[i - 1][j]) % mod;
    }
    for (int i = 0; i <= s; ++i) pr[0][i] = dp[0][i];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= s; ++j) pr[i][j] = (pr[i - 1][j] + dp[i][j]) % mod;
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j <= s; ++j) cout << i << ' ' << j << ' ' << pr[i][j] << endl;
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            cout << ans << ' ' << l << ' ' << r << ' ';
            if (r) ans = (ans + pr[r - 1][s]) % mod;
            if (l) ans = (ans - pr[l - 1][s] + mod) % mod;
            if (a[r] <= s) {
                if (s == a[r]) {
                    ans = (ans + 1) % mod;
                }
                else if (l < r) {
                    if (r) ans = (ans + pr[r - 1][s - a[r]]) % mod;
                    if (r > 1) ans = (ans - pr[r - 2][s - a[r]] + mod) % mod;
                }
            }
            cout << ans << endl;
        }
    }
    cout << ans;*/
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

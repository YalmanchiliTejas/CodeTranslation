#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
// Welcome to my source code!

const int MOD = 998244353;

ll dp[3005][3005];

int main() {
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j >= a[i]) dp[i + 1][j] += dp[i][j - a[i]];
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
        }
        ans += dp[i + 1][s];
        ans %= MOD;
    }
    cout << ans << endl;
}
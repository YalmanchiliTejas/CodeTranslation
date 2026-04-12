#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;

    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(n + 1, vector<ll>(n + 1)));

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            for (int k = 0; k < 2; k++) {
                dp[k][i][i + len] = max(-dp[k ^ 1][i + 1][i + len] + a[i], -dp[k ^ 1][i][i + len - 1] + a[i + len - 1]);
            }
        }
    }

    cout << dp[0][0][n];
}

int main() {
    cout << fixed << setprecision(20);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

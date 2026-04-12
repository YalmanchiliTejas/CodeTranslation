#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string k;
    cin >> k;
    int n = k.size();
    int d;
    cin >> d;

    const int mod = 1e9 + 7;

    vector<vector<int>> dp(n + 1, vector<int>(d));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < d; j++) {
            for (int x = 0; x < 10; x++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][(j - x % d + d) % d]) % mod;
            }
        }
    }

    int ans = mod - 1;
    int now = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k[i] - '0'; j++, now = (now + 1) % d) {
            ans = (ans + dp[n - i - 1][(d - now) % d]) % mod;
        }
    }

    cout << ans + (now == 0);
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

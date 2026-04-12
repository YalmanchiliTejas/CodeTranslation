#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int dp[n + 1][s + 1][2];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j][0] = dp[i][j][1] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            for (int k = 0; k < 2; k++) {
                if (k == 0) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (a[i - 1] == j) dp[i][j][k] += i;
                    if (a[i - 1] < j) dp[i][j][k] += dp[i - 1][j - a[i - 1]][k];
                    if (dp[i][j][k] >= mod) dp[i][j][k] -= mod;
                } else {
                    if (a[i - 1] < j) dp[i][j][k] = dp[i - 1][j - a[i - 1]][0];
                    if (a[i - 1] == j) dp[i][j][k] = i;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (ll)dp[i][s][1] * (ll)(n - i + 1);
        ans %= mod;
    }
    cout << ans;
    return 0;
}

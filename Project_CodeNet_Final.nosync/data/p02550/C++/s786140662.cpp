#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    ll n, x, m;
    cin >> n >> x >> m;
    pair<int, ll> dp[m + 1][41];
    fill(dp[0], dp[m + 1], pair<int, ll>(0, 0));
    for (int i = 0; i <= m; i++) {
        dp[i][0].first = ((ll)i * i) % m;
        dp[i][0].second = ((ll)i * i) % m;
    }
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j <= m; j++) {
            dp[j][i + 1].first = dp[dp[j][i].first][i].first;
            dp[j][i + 1].second =
                dp[j][i].second + dp[dp[j][i].first][i].second;
        }
    }
    int cur = x;
    ll ans = x;
    for (int i = 40; i >= 0; i--) {
        if (n >= (1LL << i)) {
            ans += dp[cur][i].second;
            cur = dp[cur][i].first;
            n -= (1LL << i);
        }
    }
    cout << ans - cur << endl;
    return 0;
}
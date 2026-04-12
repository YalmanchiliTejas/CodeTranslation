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
    pair<ll, ll> dp[m + 1][41];
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= 40; j++){
            dp[i][j] = {0, 0};
        }
    }
    fill(dp[0], dp[m + 1], pair<ll, ll>(0, 0));
    for (ll i = 0; i <= m; i++) {
        dp[i][0].first = (i * i) % m;
        dp[i][0].second = (i * i) % m;
    }
    for (ll i = 0; i < 40; i++) {
        for (ll j = 0; j <= m; j++) {
            dp[j][i + 1].first = dp[dp[j][i].first][i].first;
            dp[j][i + 1].second =
                dp[j][i].second + dp[dp[j][i].first][i].second;
        }
    }
    ll cur = x, ans = x;
    for (ll i = 39; i >= 0; i--) {
        if (n >= (1LL << i)) {
            ans += dp[cur][i].second;
            cur = dp[cur][i].first;
            n -= (1LL << i);
        }
    }
    cout << ans - cur << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const ll inf = 1ll << 62;
const int maxn = 2e5 + 5;
ll dp[maxn][4];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    fill_n(dp[0], maxn * 4, -inf);
    dp[0][0] = dp[1][1] = dp[2][2] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (dp[i][j] == -inf) continue;

            ll r = dp[i][j] + a[i];
            dp[i + 2][j] = max(dp[i + 2][j], r);
            dp[i + 3][j + 1] = r;
        }
    }

    ll ans = max(dp[n / 2 * 2][0], dp[n / 2 * 2 + 1][1]);
    if (n & 1) cout << max(ans, dp[n + 1][2]);
    else cout << ans;
}

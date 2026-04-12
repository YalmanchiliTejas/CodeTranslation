#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<P> items(M);
    rep(i, M) cin >> items[i].first >> items[i].second;
    vector<vector<ll>> dp(1 << N, vector<ll>(N, 0));
    dp[1][0] = 1;
    rep(i, 1 << N) {
        rep(j, N) {
            rep(m, M) {
                P p = items[m];
                ll a = p.first - 1;
                ll b = p.second - 1;
                if (i & (1 << j)) {
                    if (a == j && (i & (1 << b)) == 0) {
                        dp[i | (1 << b)][b] += dp[i][a];
                    }
                    if (b == j && (i & (1 << a)) == 0) {
                        dp[i | (1 << a)][a] += dp[i][b];
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep2(i, 1, N) {
        ans += dp[(1 << N) - 1][i];
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}

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

void Main() {
    ll N, M;
    cin >> N >> M;

    vector<vector<bool>> graph(N, vector<bool>(N, false));
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    vector<vector<ll>> dp(1 << N, vector<ll>(N, 0));
    dp[1][0] = 1;
    rep(s, 1 << N) {
        rep(to, N) {
            if ((s & (1 << to)) == 0) continue;
            ll s2 = s ^ (1 << to);
            rep(from, N) {
                if ((s2 & (1 << from)) && graph[from][to]) dp[s][to] += dp[s2][from];
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
    Main();
    return 0;
}

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
    string S;
    cin >> S;
    ll N, K;
    cin >> K;
    N = S.size();
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(2, vector<ll>(K + 2, 0)));
    dp[0][0][0] = 1;
    rep(i, N) {
        ll d = S[i] - '0';
        rep(j, 2) {
            if (j == 1) {
                d = 9;
            }
            rep(k, K + 1) {
                rep(m, d + 1) {
                    dp[i + 1][j == 1 || m < d][(m != 0 ? k + 1: k)] += dp[i][j][k];
                }
            }
        }
    }
    ll ans = dp[N][0][K] + dp[N][1][K];
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}

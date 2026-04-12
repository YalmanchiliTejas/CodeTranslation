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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));

    for (ll len = 1; len <= N; len++) {
        for (ll i = 0; i + len <= N; i++) {
            ll j = i + len;
            if ((N - len) % 2 == 0) {
                dp[i][j] = max(dp[i + 1][j] + A[i], dp[i][j - 1] + A[j - 1]);
            } else {
                dp[i][j] = min(dp[i + 1][j] - A[i], dp[i][j - 1] - A[j - 1]);
            }
        }
    }
    cout << dp[0][N] << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}

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
    string S;
    ll K;
    cin >> S >> K;
    ll N = S.size();
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(2, vector<ll>(N + 1, 0)));
    dp[0][0][0] = 1;
    rep(i, N) {
        rep(k, i + 1) {
            rep(j, 2) {
                int d = S[i] - '0';
                if (j == 1) {
                    d = 9;
                }
                rep(m, d + 1) {
                    if (m == 0) {
                        if (j == 1) {
                            dp[i + 1][1][k + 1] += dp[i][1][k];
                        } else {
                            if (m < d) {
                                dp[i + 1][1][k + 1] += dp[i][0][k];
                            }else{
                                dp[i + 1][0][k + 1] += dp[i][0][k];
                            }
                        }
                    } else {
                        if (j == 1) {
                            dp[i + 1][1][k] += dp[i][1][k];
                        } else {
                            if (m < d) {
                                dp[i + 1][1][k] += dp[i][0][k];
                            }else{
                                dp[i + 1][0][k] += dp[i][0][k];
                            }
                        }
                    }
                }
            }
        }
    }
    ll ans = dp[N][1][N - K] + dp[N][0][N - K];
    if (N- K>=0) {
        cout << ans << '\n';
    }else{
        cout << 0 << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}

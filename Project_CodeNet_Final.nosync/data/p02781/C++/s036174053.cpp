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

ll dp[105][2][105];

void Main() {
    string S;
    cin >> S;
    ll N = S.size();
    ll K;
    cin >> K;

    dp[0][0][0] = 1;
    rep(i, N) {
        ll d = S[i] - '0';
        rep(j, 2) {
            if (j == 1) {
                d = 9;
            }
            rep(k, K + 1) {
                rep(m, d + 1) {
                    if (j == 1) {
                        if (m != 0) {
                            dp[i + 1][j][k + 1] += dp[i][j][k];
                        } else {
                            dp[i + 1][j][k] += dp[i][j][k];
                        }
                    } else {
                        if (m == d) {
                            if (m != 0) {
                                dp[i + 1][j][k + 1] += dp[i][j][k];
                            } else {
                                dp[i + 1][j][k] += dp[i][j][k];
                            }
                        } else {
                            if (m != 0) {
                                dp[i + 1][1][k + 1] += dp[i][j][k];
                            } else {
                                dp[i + 1][1][k] += dp[i][j][k];
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dp[N][1][K] + dp[N][0][K] << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}

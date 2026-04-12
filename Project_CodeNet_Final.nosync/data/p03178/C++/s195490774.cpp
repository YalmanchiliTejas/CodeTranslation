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

ll dp[100005][2][105];

void Main() {
    string K;
    int D;
    cin >> K >> D;
    int N = (int) K.size();
    dp[0][0][0] = 1;

    rep(i, N) {
        int x = K[i] - '0';
        rep(j, 2) {
            if (j != 0) {
                x = 9;
            }
            rep(d, D) {
                rep(k, x + 1) {
                    if (j == 0) {
                        if (k != x) {
                            dp[i + 1][1][(d + k) % D] += dp[i][0][d];
                            dp[i + 1][1][(d + k) % D] %= MOD;
                        } else {
                            dp[i + 1][0][(d + k) % D] += dp[i][0][d];
                            dp[i + 1][0][(d + k) % D] %= MOD;
                        }
                    } else {
                        dp[i + 1][1][(d + k) % D] += dp[i][1][d];
                        dp[i + 1][1][(d + k) % D] %= MOD;
                    }
                }
            }
        }
    }
    ll ans = dp[N][1][0] + dp[N][0][0] - 1;
    if (ans < 0) ans += MOD;
    cout << ans % MOD << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}

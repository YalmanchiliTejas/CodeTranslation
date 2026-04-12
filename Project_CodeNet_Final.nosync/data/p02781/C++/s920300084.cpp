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

ll dp[105][2][5];

void Main() {
    string S;
    ll K;
    cin >> S >> K;
    ll N = S.size();
    dp[0][0][0] = 1;
    rep(i, N) {
        rep(j, 2) {
            rep(k, K + 1) {
                int d = S[i] - '0';
                if (j == 1) {
                    d = 9;
                }
                rep(m, d + 1) {
                    if (m == 0) {
                        dp[i + 1][j == 1 || m < d][k] += dp[i][j][k];
                    }else{
                        dp[i + 1][j == 1 || m < d][k + 1] += dp[i][j][k];
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

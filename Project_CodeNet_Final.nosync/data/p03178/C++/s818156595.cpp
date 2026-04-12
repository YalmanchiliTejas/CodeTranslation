#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (Int i = 0; i < (Int)(n); i++)
#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

Int dp[10001][101][2];

int main() {
    string s;
    Int d;
    cin >> s >> d;
    Int n = s.size();
    dp[0][0][1] = 1;
    rep(i, n) {
        Int x = s[i] - '0';
        rep(j, d) {
            rep(k, 10) {
                dp[i + 1][(j + k) % d][0] += dp[i][j][0];
                dp[i + 1][(j + k) % d][0] %= mod;
            }
            rep(k, x) {
                dp[i + 1][(j + k) % d][0] += dp[i][j][1];
                dp[i + 1][(j + k) % d][0] %= mod;
            }
            dp[i + 1][(j + x) % d][1] += dp[i][j][1];
            dp[i + 1][(j + x) % d][1] %= mod;
        }
    }
    // rep(j, d) {
    //     rep(i, n + 1) {
    //         cout << dp[i][j][0] << " ";
    //     }
    //     cout << endl;
    // }
    // rep(j, d) {
    //     rep(i, n + 1) {
    //         cout << dp[i][j][1] << " ";
    //     }
    //     cout << endl;
    // }
    dump((dp[n][0][0] + dp[n][0][1] - 1 + mod) % mod);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 998244353;
const int INF = 1 << 30;

lint dp[3100][3100][3] = {};

int main() {
    int n, s;
    cin >> n >> s;
    vec a(n);
    rep(i, n) cin >> a[i];

    dp[0][0][0] = 1;

    rep(i, n) {
        int ni = i+1;
        for (int j = 0; j <= s; j++) {
            rep(k, 3) {
                dp[ni][j][k] += dp[i][j][k];
                dp[ni][j][k] %= MOD;
            }
        }

        for (int j = 0; j + a[i] <= s; j++) {
            rep(k, 2) {
                if (k == 0) {
                    dp[ni][j + a[i]][1] += dp[i][j][k] * (i+1);
                    dp[ni][j + a[i]][1] %= MOD;
                    dp[ni][j + a[i]][2] += (dp[i][j][k] * (n-i) * (i+1));
                    dp[ni][j + a[i]][2] %= MOD;
                }
                else {
                    dp[ni][j + a[i]][1] += dp[i][j][k];
                    dp[ni][j + a[i]][1] %= MOD;
                    dp[ni][j + a[i]][2] += (dp[i][j][k] * (n-i));
                    dp[ni][j + a[i]][2] %= MOD;
                }
            }
        }
    }

    cout << dp[n][s][2] << endl;
    return 0;
}
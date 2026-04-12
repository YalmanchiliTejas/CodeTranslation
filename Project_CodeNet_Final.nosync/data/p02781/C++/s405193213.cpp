#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

ll dp[110][2][4];

int main() {
    string S;
    int K;
    cin >> S >> K;

    dp[0][0][0] = 1;
    rep(i, S.size()) {
        int c = S[i] - '0';

        rep(d, 10) {
            if (d < c) {
                if (d == 0) {
                    rep(k, 4) dp[i + 1][1][k] += dp[i][0][k];
                    rep(k, 4) dp[i + 1][1][k] += dp[i][1][k];
                } else {
                    rep(k, 3) dp[i + 1][1][k + 1] += dp[i][0][k];
                    rep(k, 3) dp[i + 1][1][k + 1] += dp[i][1][k];
                }
            } else if (d == c) {
                if (d == 0) {
                    rep(k, 4) dp[i + 1][0][k] += dp[i][0][k];

                    rep(k, 4) dp[i + 1][1][k] += dp[i][1][k];
                } else {
                    rep(k, 3) dp[i + 1][0][k + 1] += dp[i][0][k];

                    rep(k, 3) dp[i + 1][1][k + 1] += dp[i][1][k];
                }
            } else {
                if (d == 0) {
                    rep(k, 4) dp[i + 1][1][k] += dp[i][1][k];
                } else {
                    rep(k, 3) dp[i + 1][1][k + 1] += dp[i][1][k];
                }
            }
        }
    }

    cout << dp[S.size()][0][K] + dp[S.size()][1][K] << endl;
}

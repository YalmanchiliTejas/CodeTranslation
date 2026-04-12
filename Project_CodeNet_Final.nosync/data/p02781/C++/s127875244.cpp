#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

ll dp[110][2][4]; // dp[i][j][k] : i:見た文字数, j:smaller?, k: 0でない数字の個数

int main() {
    string S;
    int K;
    cin >> S >> K;

    dp[0][0][0] = 1;
    rep(i, S.size()) {
        rep(j, 2) {
            rep(k, 4) {
                int nd = S[i] - '0';
                rep(d, 10) {
                    int ni = i + 1, nj = j, nk = k;
                    if (d != 0) nk++;
                    if (nk > K) continue;
                    if (j == 0) {
                        if (d > nd) continue;
                        if (d < nd) nj = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[S.size()][0][K] + dp[S.size()][1][K] << endl;
}

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int MAX_LEN = 10010, MAX_D = 100;
constexpr int MOD = 1e9 + 7;
int dp[MAX_LEN][2][MAX_D];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    string K;
    int D;

    cin >> K >> D;

    const int len = K.size();
    dp[0][1][0] = 1;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int l = 0; l < D; ++l) {
                if (dp[i][j][l] == 0) continue;

                if (j == 0) { //制限なし
                    for (int m = 0; m < 10; ++m)
                        (dp[i + 1][0][(l + m) % D] += dp[i][j][l]) %= MOD;
                }
                else { // 制限あり
                    const int ub = (int)(K[i] - '0');
                    for (int m = 0; m < ub; ++m)
                        (dp[i + 1][0][(l + m) % D] += dp[i][j][l]) %= MOD;
                    (dp[i + 1][1][(l + ub) % D] += dp[i][j][l]) %= MOD;
                }
            }
        }
    }

    ll res = (dp[len][0][0] + dp[len][1][0]) % MOD;
    cout << (res - 1 + MOD) % MOD << endl;

    return 0;
}

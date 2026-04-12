#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;
constexpr i64 MOD = 1e9 + 7;

int main() {
    string K;
    cin >> K;
    int D;
    cin >> D;
    vector<vvi> dp(K.size() + 1, vvi(2, vi(D)));
    dp[0][0][0] = 1;
    for (int i = 0; i < K.size(); i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < D; k++) {
                for (int d = 0; d <= (j ? 9 : K[i] - '0'); d++) {
                    dp[i + 1][j | (d < K[i] - '0')][(k + d) % D] += dp[i][j][k];
                    dp[i + 1][j | (d < K[i] - '0')][(k + d) % D] %= MOD;
                }
            }
        }
    }
    cout << (dp[K.size()][0][0] + dp[K.size()][1][0] - 1 + MOD) % MOD << endl;
}

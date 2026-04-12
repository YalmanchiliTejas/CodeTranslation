#include <bits/stdc++.h>
using namespace std;

int main() {
    long long mod = 1e9 + 7;
    string K;
    int D;
    cin >> K >> D;
    long long dp[K.size() + 1][2][D + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < K.size(); ++i) {
        for (int j = 0; j <= 1; ++j) {
            int lim = j ? 9 : K[i] - '0';
            for (int k = 0; k < D; ++k) {
                for (int l = 0; l <= lim; ++l) {
                    (dp[i + 1][j || l < lim][(k + l) % D] += dp[i][j][k]) %= mod;
                }
            }
        }
    }
    cout << (dp[K.size()][0][0] + dp[K.size()][1][0] - 1 + mod) % mod << endl;

    return 0;
}
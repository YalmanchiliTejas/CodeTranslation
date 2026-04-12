#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
// (i, b, d) => n
// i桁目より上が決定
// b = K以下確定 ? 1 : 0
// そこまでの各桁の数字の総和が d mod D となる個数n

const i64 MOD = 1e9 + 7;
i64 dp[10001][2][100];

int main() {
    string K;
    int D, N;
    cin >> K >> D;
    reverse(WHOLE(K));
    N = K.size();
    for(int i = 0; i <= N; i++) {
        for(int b = 0; b < 2; b++) {
            for(int d = 0; d < D; d++) {
                dp[i][b][d] = 0;
            }
        }
    }
    dp[N][0][0] = 1;
    for(int i = N - 1; i >= 0; i--) {
        int n = K[i] - '0';
        for(int d = 0; d < D; d++) {
            for(int x = 0; x < n; x++) {
                dp[i][1][d] += dp[i + 1][0][(d - x + 100 * D) % D];
            }
            for(int x = 0; x < 10; x++) {
                dp[i][1][d] += dp[i + 1][1][(d - x + 100 * D) % D];
            }
            dp[i][0][d] += dp[i + 1][0][(d - n + 100 * D) % D];
            dp[i][0][d] %= MOD;
            dp[i][1][d] %= MOD;
        }
    }
    cout << (dp[0][1][0] + dp[0][0][0] - 1 + MOD) % MOD << endl;
}
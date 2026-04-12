#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef long long LL;
const int MOD = 1000000007;

int main(){
    int N, X;
    LL D;

    LL inv[2005] = {};
    inv[1] = 1;
    for(int i = 2; i < 2005; i++) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    }

    while(cin >> N >> D >> X && N > 0) {

        static LL dp[2005][2005] = {};
        LL sum[2005] = {};

        dp[0][0] = 1;
        REP(i, N + 2) sum[i + 1] = sum[i] + dp[0][i];

        REP(i, N + 2) {
            REP(j, N + 2) {
                //dp[i + 1][j] = dp[i][j - 1] + dp[i][j - 2] + ... + dp[i][j - X + 1]
                //dp[i + 1][j] = sum[j] - sum[j - X + 1]
                dp[i + 1][j] = sum[j] - (j - X + 1 >= 0 ? sum[j - X + 1] : 0);
                dp[i + 1][j] += MOD;
                dp[i + 1][j] %= MOD;
            }
            REP(j, N + 2){
                sum[j + 1] = (sum[j] + dp[i + 1][j]);
                sum[j + 1] %= MOD;
            }
        }

        LL C = 1;
        LL ans = 0;

        for(int i = 1; i <= N && i <= D; i++) {
            // C(D, i) * dp[i][N]
            C *= (D - i + 1) % MOD;
            C %= MOD;
            C *= inv[i];
            C %= MOD;

            ans += C * dp[i][N] % MOD;
            ans %= MOD;
        }

        cout << ans << endl;
    }
    return 0;
}
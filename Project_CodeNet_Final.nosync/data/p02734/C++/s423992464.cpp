#include <bits/stdc++.h>
using namespace std;
int A[3001];
int MOD = 998244353;
long long dp[3010][6010][3] = {0};

int main() {
    int N, S;
    dp[0][0][0] = 1;

    scanf("%d %d", &N, &S);
    for(int i=0;i<N;i++) {
        scanf("%d", &A[i]);
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<=S;j++) {
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j+A[i]][1] += dp[i][j][0] * (i+1);
            dp[i+1][j+A[i]][2] += dp[i][j][0] * (i+1) * (N-i);

            dp[i+1][j][1] += dp[i][j][1];
            dp[i+1][j+A[i]][1] += dp[i][j][1];
            dp[i+1][j+A[i]][2] += dp[i][j][1] * (N-i);

            dp[i+1][j][2] += dp[i][j][2];

            dp[i+1][j][0] %= MOD;
            dp[i+1][j][1] %= MOD;
            dp[i+1][j][2] %= MOD;
        }
    }

    printf("%lld\n", dp[N][S][2]);
    return 0;
}
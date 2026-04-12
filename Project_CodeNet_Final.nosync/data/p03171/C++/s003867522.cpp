#include <bits/stdc++.h>
// L - Deque

using namespace std;

int a[3003];
long long dp[3003][3003][2];

int main() {
    int N,i,j,k;

    scanf("%d",&N);

    for (i = 0;i < N;i++) {
        scanf("%d",&a[i]);
        dp[i][i][0] = a[i];
        dp[i][i][1] = a[i];
    }

    for (i = 0;i < N;i++) {
        for (j = 0;(j + i) < N;j++) {
            for (k = 0;k < 2;k++)
                dp[j][j + i][k] = max(a[j + i] - dp[j][j + i - 1][1 - k],a[j] - dp[j + 1][j + i][1 - k]);
        }
    }

    printf("%lld\n",dp[0][N - 1][0]);

    return 0;
}

#include <stdio.h>

int N;
int A[3000];
long long dp[3000][3000];

long long max(long long x, long long y) {
    return x > y ? x : y;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        dp[i][i] = A[i];
    }
    for (int d = 1; d < N; d++) {
        for (int l = 0; l + d < N; l++) {
            int r = l + d;
            dp[l][r] = max(-dp[l + 1][r] + A[l], -dp[l][r - 1] + A[r]);
        }
    }
    printf("%lld\n", dp[0][N - 1]);
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int N;
long long A[200001], dp[200001];
int main () {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
    dp[0] = dp[1] = 0;
    long long x = A[1];
    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            dp[i] = max(dp[i-2]+A[i], x);
        }
        else {
            dp[i] = max(dp[i-2]+A[i], dp[i-1]);
            x += A[i];
        }
    }
    printf("%lld\n", dp[N]);
}
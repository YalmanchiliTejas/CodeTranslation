#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    long long ans = 0;
    for (int i = K + 1; i <= N; i++) {
        ans += (i - K) * (N / i);
        ans += max(0, N % i - K + 1);
        if (K == 0) ans -= 1;
    }

    printf("%lld\n", ans);
    return 0;
}
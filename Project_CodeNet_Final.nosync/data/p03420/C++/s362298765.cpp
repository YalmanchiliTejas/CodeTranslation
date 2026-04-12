#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K;
    scanf("%d%d", &n, &K);
    long long tot = 0;
    for (int b = 1; b <= n; b++) {
        if (b - 1 < K) {
            continue;
        }
        tot += (long long)(n / b) * (b - K);
        int max_K = n - (n / b) * b;
        if (max_K >= K) {
            tot += max_K - K + 1;
        }
    }
    if (K == 0) {
        tot -= n;
    }
    printf("%lld\n", tot);
    return 0;
}
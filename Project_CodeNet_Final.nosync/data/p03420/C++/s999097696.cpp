#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K;
    scanf("%d %d", &n, &K);
    if (!K) printf("%lld\n", 1LL * n * n), exit(0);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j += i) {
            int k = min(n, (j / i + 1) * i - 1);
            ans += max(0, k % i - K + 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
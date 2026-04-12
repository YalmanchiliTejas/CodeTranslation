#include <bits/stdc++.h>
using namespace std;
int n, s[100005];
int main() {
    // freopen("data.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
    long long ans = 0;
    for (int d = 1; d < n; ++d) {
        long long sum = 0;
        for (int k = 1; (k + 1) * d < n - 1; ++k) {
            if (k * d >= n - 1 - k * d && (n - 1) % d == 0) break;
            sum += 1LL * s[k * d];
            sum += 1LL * s[n - 1 - k * d];
            ans = max(ans, sum);
        }
    }
    printf("%lld\n", ans);
}
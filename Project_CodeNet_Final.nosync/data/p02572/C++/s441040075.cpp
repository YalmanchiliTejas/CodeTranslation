#include <cstring>
#include <cstdio>
using ll = long long;
const int M = 2e5 + 10, mod = 1e9 + 7;
ll arr[M], sum[M], n, ans = 0;
int main () {
    scanf ("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%lld", &arr[i]);
        sum[i] = sum[i - 1] + arr[i];
    }
    for (int i = 2; i <= n; i++) {
        ans = (ans + (sum[i - 1] % mod * arr[i] % mod)) % mod;
    }
    printf("%lld", ans);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7, mod = 1e9 + 7;
typedef long long ll;
int n;
ll a[maxn], b[maxn];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = n; i >= 1; i--) b[i] = (b[i + 1] + a[i]) % mod;
    ll ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        ans = (ans + a[i] * b[i + 1] % mod) % mod;
    }
    printf("%lld\n", ans);
}

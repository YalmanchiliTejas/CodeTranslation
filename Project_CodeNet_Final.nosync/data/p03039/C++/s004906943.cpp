//written by NewbieChd
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxN = 200003, yyb = 1e9 + 7;
int fac[maxN], invFac[maxN];
inline int power(int x, int y) {
    int o = 1;
    while (y) {
        if (y & 1)
            o = 1ll * o * x % yyb;
        x = 1ll * x * x % yyb, y >>= 1;
    }
    return o;
}

int main() {
    int n, m, k, lim, i, ans = 0;
    scanf("%d%d%d", &n, &m, &k), k -= 2;
    lim = n * m - 2, fac[0] = 1;
    for (i = 1; i <= lim; ++i)
        fac[i] = 1ll * fac[i - 1] * i % yyb;
    invFac[lim] = power(fac[lim], yyb - 2);
    for (i = lim; i; --i)
        invFac[i - 1] = 1ll * invFac[i] * i % yyb;
    for (i = 1; i < n; ++i)
        ans = (1ll * i * (n - i) * m * m + ans) % yyb;
    for (i = 1; i < m; ++i)
        ans = (1ll * i * (m - i) * n * n + ans) % yyb;
    ans = 1ll * ans * fac[lim] % yyb * invFac[k] % yyb * invFac[lim - k] % yyb;
    printf("%d\n", ans);
    return 0;
}

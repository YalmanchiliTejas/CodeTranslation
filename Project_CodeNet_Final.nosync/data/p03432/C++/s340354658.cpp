#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

int read();
int M(int x) { return x >= mod ? x - mod : x; }
int fsp(int bs, int p) {
    int rt = 1;
    while (p) {
        if (p & 1)
            rt = 1ll * rt * bs % mod;
        bs = 1ll * bs * bs % mod, p >>= 1;
    }
    return rt;
}
int C2(int x) { return x * (x - 1) / 2; }
int fac[10004], caf[10004];
int C(int x, int y) { return 1ll * fac[x] * caf[y] % mod * caf[x - y] % mod; }
void init() {
    int lim = 10000;
    fac[0] = 1;
    for (int i = 1; i <= lim; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
    caf[lim] = fsp(fac[lim], mod - 2);
    for (int i = lim; i >= 1; --i) caf[i - 1] = 1ll * caf[i] * i % mod;
}

int rtt[20004], O[20004], ny;
void getrtt(int w, int len) {
    for (int i = 1; i < len; ++i) rtt[i] = rtt[i >> 1] >> 1 | ((i & 1) << w);
    for (int l = 2; l <= len; l <<= 1) O[l] = fsp(3, (mod - 1) / l);
    ny = fsp(len, mod - 2);
}

struct Poly {
    int x[20004];
    int &operator[](int p) { return x[p]; }
    void ntt(int len) {
        for (int i = 1; i < len; ++i)
            if (rtt[i] > i)
                swap(x[rtt[i]], x[i]);
        for (int l = 2; l <= len; l <<= 1) {
            for (int i = 0, m = l >> 1; i < len; i += l) {
                for (int j = i, tO = 1, t; j < i + m; ++j) {
                    t = 1ll * tO * x[j + m] % mod, tO = 1ll * tO * O[l] % mod;
                    x[j + m] = M(x[j] - t + mod), x[j] = M(x[j] + t);
                }
            }
        }
    }
    void idft(int len) {
        ntt(len), reverse(x + 1, x + len);
        for (int i = 0; i < len; ++i) x[i] = 1ll * x[i] * ny % mod;
    }
} f, g, tf;

int n, m;
int main() {
    n = read(), m = read();
    init();
    int w = 1, len = 2;
    while (len < 2 * n + 1) len <<= 1, ++w;
    for (int i = 1; i <= n; ++i) g[i] = caf[i + 2];
    getrtt(w - 1, len), g.ntt(len);
    tf[0] = f[0] = 1;
    for (int i = 1; i <= m; ++i) {
        f.ntt(len);
        for (int j = 0; j < len; ++j) f[j] = 1ll * f[j] * g[j] % mod;
        f.idft(len);
        for (int j = 0; j <= n; ++j) {
            tf[j] = M(1ll * f[j] * fac[j + 2] % mod + 1ll * tf[j] * (1 + j + C2(j)) % mod);
            f[j] = 1ll * tf[j] * caf[j] % mod;
        }
        for (int j = n + 1; j < len; ++j) f[j] = 0;
    }
    int res = 0;
    for (int i = 0; i <= n; ++i) res = M(res + 1ll * C(n, i) * tf[i] % mod);
    printf("%d\n", res);
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
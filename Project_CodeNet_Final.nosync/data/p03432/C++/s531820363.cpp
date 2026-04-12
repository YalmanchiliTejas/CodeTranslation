#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, G = 3;
int n, m;
int dp[210][8010];
int f[32010], g[32010];
int rev[32010];
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
inline void getrev(int l) {
    for (int i = 1; i < 1 << l; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
}
inline void NTT(int *a, int n, int type) {
    for (int i = 1; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int p = 1; p < n; p <<= 1) {
        int wn = power(G, type == 1 ? mod / 2 / p : mod - 1 - mod / 2 / p);
        for (int s = 0; s < n; s += p << 1) {
            int w = 1;
            for (int i = 0; i < p; i++) {
                int h1 = a[s + i], h2 = 1ll * w * a[s + p + i] % mod;
                a[s + i] = (h1 + h2) % mod;
                a[s + p + i] = (h1 - h2 + mod) % mod;
                w = 1ll * w * wn % mod;
            }
        }
    }
    if (type == -1) {
        int inv = power(n, mod - 2);
        for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * inv % mod;
    }
}
inline void mult(int *a, int sizea, int *b, int sizeb, int *c, int sizec) {
    int l = 0;
    for (; 1 << l < sizea + sizeb; l++);
    getrev(l);
    for (int i = 0; i < 1 << l; i++) {
        f[i] = i < sizea ? a[i] : 0;
        g[i] = i < sizeb ? b[i] : 0;
    }
    NTT(f, 1 << l, 1);
    NTT(g, 1 << l, 1);
    for (int i = 0; i < 1 << l; i++) f[i] = 1ll * f[i] * g[i] % mod;
    NTT(f, 1 << l, -1);
    for (int i = 0; i < sizec; i++) c[i] = f[i];
}
int fac[8010];
int facinv[8010];
int tmp[8010];
int main() {
    scanf("%d%d", &n, &m);
    fac[0] = 1;
    for (int i = 1; i <= n + 2; i++) fac[i] = 1ll * i * fac[i - 1] % mod; 
    facinv[n + 2] = power(fac[n + 2], mod - 2);
    for (int i = n + 2; i > 0; i--) facinv[i - 1] = 1ll * i * facinv[i] % mod;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) tmp[i] = facinv[i + 2];
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) dp[i - 1][j] = 1ll * dp[i - 1][j] * facinv[j] % mod;
        mult(dp[i - 1], n + 1, tmp, n + 1, dp[i], n + 1);
        for (int j = 0; j <= n; j++) dp[i - 1][j] = 1ll * dp[i - 1][j] * fac[j] % mod;
        for (int j = 0; j <= n; j++) dp[i][j] = (1ll * dp[i][j] * fac[j + 2] + 1ll * (1 + j * (j + 1) / 2) * dp[i - 1][j]) % mod;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + 1ll * fac[n] * facinv[i] % mod * facinv[n - i] % mod * dp[m][i]) % mod;
    return cout << ans << endl, 0;
}
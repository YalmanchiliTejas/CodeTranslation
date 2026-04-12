#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
int n, m, s[N][N], ans, c[N][N], f[N];
int qpow(int a, int b, int mod) {
    int c = 1;
    while(b) {
        if(b & 1) c = 1ll * c * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return c;
}
int main() {
    scanf("%d %d", &n, &m);
    s[0][0] = 1;
    ++n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            s[i][j] = (1ll * j * s[i - 1][j] + s[i - 1][j - 1]) % m;
    c[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % m;
    }
    --n;
    for(int i = 0; i <= n; ++i) {
        int b1 = qpow(2, n - i, m - 1), b2 = qpow(2, n - i, m);
        for(int j = 0; j <= i; ++j)
            (f[i] += 1ll * s[i + 1][j + 1] * qpow(b2, j, m) % m) %= m;
        f[i] = 1ll * f[i] * c[n][i] % m * qpow(2, b1, m) % m;
        if(i & 1) (ans -= f[i]) %= m;
        else (ans += f[i]) %= m;
    }
    printf("%d\n", (ans + m) % m);
    return 0;
}

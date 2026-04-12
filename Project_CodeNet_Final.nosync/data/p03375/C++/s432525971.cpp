#include <bits/stdc++.h>
using namespace std;
int mod;
int fac[3010], facinv[3010], g[3010][3010], n;
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
int C[3010][3010];
int main() {
    cin >> n >> mod;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
    facinv[n] = power(fac[n], mod - 2);
    for (int i = n; i --> 0; ) facinv[i] = 1ll * (i + 1) * facinv[i + 1] % mod;
    int ans = 0;
    for (int i = 0; i <= n; i++) g[i][0] = 1, C[i][0] = C[i][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) g[i][j] = (g[i - 1][j - 1] + 1ll * (j + 1) * g[i - 1][j]) % mod, C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    for (int i = 0; i <= n; i++) {
        int now = 1ll * (i & 1 ? mod - 1 : 1) * C[n][i] % mod;
        mod--;
        int tmp = power(2, n - i);
        mod++;
        now = 1ll * now * power(2, tmp) % mod;
        for (int j = 0; j <= i; j++) {
            ans = (ans + 1ll * now * g[i][j] % mod * power(power(2, n - i), j)) % mod;
        }
    }
    return cout << ans << endl, 0;
}
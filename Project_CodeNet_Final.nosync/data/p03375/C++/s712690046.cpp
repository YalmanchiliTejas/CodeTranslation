#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 3003
using namespace std;

int n, Mod, S2[N][N], pw[N][N], C[N][N];

inline int fsp(int x, int k, int p = Mod) {
    int res = 1;
    while (k) {
        if (k & 1) res = 1ll * res * x % p;
        x = 1ll * x * x % p, k >>= 1;
    } return res;
}

inline int get(int x) {
    long long res = 0, tmp = fsp(2, fsp(2, n - x, Mod - 1));
    for (int i = 0; i <= x; ++i)
        res = (res + 1ll * S2[x + 1][i + 1] * pw[x][i] % Mod * tmp % Mod) % Mod;
    return res;
}

int main() {
#ifdef isLOCAL
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n >> Mod;
    long long ans = 0;
    S2[0][0] = 1;
    for (int i = 0; i <= n + 1; ++i)
        for (int j = C[i][0] = 1; j <= i; ++j)
            S2[i][j] = (S2[i - 1][j - 1] + 1ll * S2[i - 1][j] * j) % Mod,
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
    for (int i = 0; i <= n; ++i) {
        int tmp = fsp(2, n - i);
        for (int j = pw[i][0] = 1; j <= i; ++j)
            pw[i][j] = 1ll * tmp * pw[i][j - 1] % Mod;
    }
    for (int i = 0; i <= n; ++i)
        ans = (ans + ((i & 1) ? -1ll : 1ll) * get(i)\
        * C[n][i] % Mod) % Mod;
    if (ans < 0) ans += Mod;
    cout << ans << endl;
 
    return 0;
}

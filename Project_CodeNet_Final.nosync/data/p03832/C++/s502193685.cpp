#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> II;

const int N = (int) 1e3 + 10;
const int P = (int) 1e9 + 7;
int n, a, b, c, d;
int fac[N], inv[N], g[N][N], dp[N][N];

int Power(int a, int k) {
    int ans = 1;
    while (k) {
        if (k & 1) ans = (LL) ans * a % P;
        a = (LL) a * a % P;
        k >>= 1;
    }
    return ans;
}

int main() {
    #ifdef LOCAL
        freopen("Data.inp", "r", stdin);
        freopen("Data.out", "w", stdout);
    #endif

    scanf("%d", &n);
    scanf("%d%d", &a, &b);
    scanf("%d%d", &c, &d);

    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 1000; ++i) {
        fac[i] = (LL) fac[i - 1] * i % P;
        inv[i] = Power(fac[i], P - 2);
    }
    for (int v = 1; v <= 1000; ++v) {
        g[v][0] = 1;
        for (int i = 1; i <= 1000; ++i) g[v][i] = (LL) g[v][i - 1] * inv[v] % P;
    }

    dp[a - 1][0] = 1;
    for (int v = a; v <= b; ++v)
        for (int s = 0; s <= n; ++s) {
            dp[v][s] = dp[v - 1][s];
            for (int i = c; i <= d && i * v <= s; ++i) {
                int coef = (LL) fac[i * v] * g[v][i] % P * inv[i] % P;
                int ways = (LL) fac[s] * inv[i * v] % P * inv[s - i * v] % P;
                dp[v][s] = (dp[v][s] + (LL) dp[v - 1][s - i * v] * coef % P * ways) % P;
            }
        }

    printf("%d", dp[b][n]);
    return 0;
}

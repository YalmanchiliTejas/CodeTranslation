#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <bitset>
#include <queue>
#include <random>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1005;
const int mod = 1e9 + 7;

ll dp[2][N];
ll lul[N][N];
ll f[N], fr[N];

ll binpow(ll a, int p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

ll cnk(int n, int k) {
    return f[n] * fr[k] % mod * fr[n - k] % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    f[0] = fr[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % mod;
        fr[i] = binpow(f[i], mod - 2);
    }
    for (int j = 1; j <= n; j++) {
        lul[0][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % j) {
                continue;
            }
            lul[i][j] = lul[i - j][j] * f[(i - j) / j] % mod * cnk(i, j) % mod * fr[i / j] % mod;
        }
    }
    dp[0][0] = 1;
    for (int i = a; i <= b; i++) {
        int u = (i - a) & 1;
        int v = u ^ 1;
        copy(dp[u], dp[u] + n + 1, dp[v]);
        for (int w = 0; w < n; w++) {
            for (int k = c; k <= d && w + k * i <= n; k++) {
                dp[v][w + k * i] += dp[u][w] * cnk(n - w, k * i) % mod * lul[k * i][i];
                dp[v][w + k * i] %= mod;
            }
        }
    }
    cout << dp[(b - a + 1) & 1][n] << endl;
    return 0;
}
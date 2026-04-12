#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

#define int long long

const int MAX_N = 3005;
int n, mod, fact[MAX_N+1], invfact[MAX_N+1], pow2[MAX_N * MAX_N + 100];

int powMod(int a, int p)
{
    int ans = 1;
    while (p > 0) {
        if (p & 1) ans = ans * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return ans;
}

int powMod(int a, int p, int m)
{
    int ans = 1;
    while (p > 0) {
        if (p & 1) ans = ans * a % m;
        p >>= 1;
        a = a * a % m;
    }
    return ans % m;
}

int combi(int n, int k)
{
    return k > n ? 0 : (fact[n] * invfact[k] % mod) * invfact[n-k] % mod;
}

signed main()
{
    cin >> n >> mod;

    // pre-process
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
		fact[i] = fact[i-1] * i % mod;
        invfact[i] = powMod(fact[i], mod - 2);
    }

    pow2[0] = 1;
    for (int i = 1; i <= MAX_N * MAX_N + 50; ++i) pow2[i] = (pow2[i-1] * 2) % mod;

    int stirling[MAX_N+1][MAX_N+1]; // s2[n][k]
    // n = 1
    for (int j = 0; j <= MAX_N; ++j) stirling[1][j] = 0;
    stirling[1][1] = 1;

    for (int i = 2; i <= MAX_N; ++i) {
		stirling[i][0] = 0;
        for (int j = 1; j <= MAX_N; ++j) {
            stirling[i][j] = (stirling[i-1][j-1] + stirling[i-1][j] * j) % mod;
        }
    }

    int f[n+1];
    f[0] = powMod(2, powMod(2, n, mod - 1));
//    cerr << f[0] << ' ';
    for (int x = 1; x <= n; ++x) {
        f[x] = 0;
        for (int i = 1; i <= x; ++i) {
            f[x] = (f[x] + stirling[x][i] * ((pow2[(n-x)*(i-1)] * i + pow2[(n-x)*i]) % mod)) % mod;
        }
//        cerr << f[x] << ' ';
        f[x] *= powMod(2, powMod(2, n-x, mod - 1));
        f[x] %= mod;
        f[x] *= combi(n, x);
        f[x] %= mod;
    }

//    cerr << endl;
//    for (int x = 0; x <= n; ++x) cerr << f[x] << ' '; cerr << endl;

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += (i & 1) ? mod - f[i] : f[i];
        ans %= mod;
    }
    cout << ans << endl;
}

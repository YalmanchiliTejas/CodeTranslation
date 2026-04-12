#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstring>

using namespace std;

const int MOD = (int)1e9 + 7;

const int N = 1000 + 5;

typedef long long LL;

int n;
int a, b, c, d;
LL f[N][N];
LL binom[N][N];
LL coef[N][N];
LL inv_fact[N];

// ax + by = gcd(a, b), |x| + |y| is minimum
void exgcd(LL a, LL b, LL &g, LL &x, LL &y) {
    if (!b) x = 1, y = 0, g = a;
    else {
        exgcd(b, a % b, g, y, x);
        y -= x * (a / b);
    }
}

// ax = 1 (mod m), gcd(a, m) = 1
LL mod_inv(LL a, LL m) {
    LL d, x, y;
    exgcd(a, m, d, x, y);
    return d == 1 ? (x % m + m) % m : -1;
}

void solve()
{
    inv_fact[0] = 1;
    for(int i = 1; i < N; ++ i) {
        inv_fact[i] = inv_fact[i - 1] * mod_inv(i, MOD) % MOD;
    }
    binom[0][0] = 1;
    for(int i = 1; i < N; ++ i) {
        binom[i][0] = 1;
        for(int j = 1; j <= i; ++ j) {
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % MOD;
        }
    }

    cin >> n >> a >> b >> c >> d;
    for(int i = 1; i <= n; ++ i) {
        coef[i][0] = 1;
        for(int j = 1; j * i <= n; ++ j) {
            coef[i][j] = coef[i][j - 1] * binom[i * j][i] % MOD;
        }
    }

    f[1][0] = 1;
    for(int i = 1; i <= n; ++ i) {
        for(int j = 0; j <= n; ++ j) {
            (f[i + 1][j] += f[i][j]) %= MOD;
            if (i >= a && i <= b) {
                for(int k = c; k <= d; ++ k) {
                    if (j + k * i > n) break;
                    (f[i + 1][j + k * i] += f[i][j] * coef[i][k] % MOD * binom[n - j][k * i] % MOD * inv_fact[k]) %= MOD;
                }
            }
        }
    }

    /*
       for(int i = 0; i <= n; ++ i) {
       for(int j = 0; j < n; ++ j) {
       (f[i][j + 1] += f[i][j]) %= MOD;
       if ((j + 1) < a || (j + 1) > b) continue;
       for(int k = c; k <= d; ++ k) {
       if (i + k * (j + 1) > n) break;
       (f[i + k * (j + 1)][j + 1] += f[i][j] * binom[n - i][k * (j + 1)]) %= MOD;
       }
       }
       }
     */

    cout << f[n + 1][n] << endl;
}

int main()
{
    solve();
    return 0;
}


#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 1e2, mod = 1e9 + 7;
int n, h[nsz + 5], dp[nsz + 5], f[nsz + 5][nsz + 5];

num inline qpow(num a, int p) {
    num res = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cont (i, n) {
        cin >> h[i];
    }
    dp[1] = qpow(2, h[1]);
    cont (i, n) {
        f[1][i] = 2 * qpow(2, h[1] - h[i]) % mod;
    }
    circ (i, 2, n) {
        dp[i] = (dp[i - 1] + f[i - 1][i]) * qpow(2, h[i] - h[i - 1]) % mod;
        cont (j, n) {
            if (h[i] <= h[i - 1]) {
                f[i][j] = h[i] > h[j] ? f[i - 1][j] : f[i - 1][i];
            } else {
                if (h[i] > h[j]) {
                    f[i][j] = f[i - 1][j] * qpow(2, h[i] - (h[j] > h[i - 1] ? h[j] : h[i - 1])) % mod;
                } else {
                    f[i][j] = f[i - 1][j];
                }
            }
            f[i][j] += f[i - 1][i] * qpow(2, h[i] - max(h[i - 1], h[j])) % mod;
            f[i][j] %= mod;
        }
    }
    cout << dp[n] << ln;
}

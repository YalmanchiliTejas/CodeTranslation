#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int mod_inv(int x, int m) {
    long long a = 1, b = 0, c = 0, d = 1, p = x, q = m;
    while (q != 0) {
        long long c0 = c, d0 = d, r = p / q;
        c = (a - c * r) % m;
        d = (b - d * r) % x;
        a = c0; b = d0;
        int t = p - r * q; p = q; q = t;
    }
    return (a + m) % m;
}

int mod_pow(int x, int e, int m) {
    long long ans = 1, p = x % m;
    while (e > 0) {
        if (e % 2 != 0) ans = (ans * p) % m;
        p = (p * p) % m;
        e >>= 1;
    }
    return ans;
}

int fact[1000001], finv[1000001];

int main() {
    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    const int M = (int)1e9 + 7;
    fact[0] = 1;
    finv[0] = 1;
    for (int i = 1; i <= n*n; i++) {
        fact[i] = ((long long)fact[i-1] * i) % M;
        finv[i] = mod_inv(fact[i], M);
    }
    long long dp[1001][1000] = {};
    dp[0][a] = 1;
    for (int m = c*a; m <= min(n, d*a); m += a)
        dp[m][a] = (long long)fact[m] * finv[m/a] % M * mod_pow(finv[a], m/a, M) % M;
    for (int k = a+1; k <= b; k++) {
        dp[0][k] = 1;
        for (int m = 1; m <= n; m++) {
            dp[m][k] = dp[m][k-1];
            for (int t = m - c*k; t >= max(0, m - d*k); t -= k) {
                dp[m][k] += dp[t][k-1] * fact[m] % M * finv[t] % M * finv[(m-t)/k] % M * mod_pow(finv[k], (m-t)/k, M) % M;
            }
            dp[m][k] %= M;
        }
    }
    cout << (dp[n][b] + M) % M << endl;
}

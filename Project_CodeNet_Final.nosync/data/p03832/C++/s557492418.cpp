#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int N, A, B, C, D;
int mod = 1e9 + 7;
int dp[1100][1100];
int fact[1100];
int fact_inv[1100][1100];

//拡張ユークリッドの互除法
int extgcd(int a, int b, int& x, int& y) {
    int d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

// mod逆元
int mod_inverse(int a, int m) {
    int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

//繰り返し二乗法
int mod_pow(int x, int n, int m) {
    if (n == 0)
        return 1;
    int res = mod_pow(x * x % m, n / 2, m);
    if (n & 1)
        res = res * x % m;
    return res;
}

int DP(int n, int a) {
    if (dp[n][a] != -1) {
        return dp[n][a];
    }
    if (n == 0) {
        return dp[n][a] = 1;
    }
    if (a > B) {
        return dp[n][a] = 0;
    }
    dp[n][a] = DP(n, a + 1);
    for (int i = C; i <= D && n >= a * i; i++) {
        int pattern = fact[n] * fact_inv[1][n - a * i] % mod * fact_inv[i][a] %
                      mod * fact_inv[1][i] % mod;
        (dp[n][a] += DP(n - a * i, a + 1) * pattern % mod) %= mod;
    }
    return dp[n][a];
}

signed main() {
    cin >> N >> A >> B >> C >> D;
    fact[0] = 1;
    for (int i = 1; i < 1100; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    for (int i = 0; i < 1100; i++) {
        fact_inv[1][i] = mod_inverse(fact[i], mod);
    }
    for (int i = 2; i < 1100; i++) {
        for (int j = 0; j < 1100; j++) {
            fact_inv[i][j] = fact_inv[i - 1][j] * fact_inv[1][j] % mod;
        }
    }
    for (int i = 0; i < 1100; i++) {
        for (int j = 0; j < 1100; j++) {
            dp[i][j] = -1;
        }
    }
    cout << DP(N, A) << endl;
}
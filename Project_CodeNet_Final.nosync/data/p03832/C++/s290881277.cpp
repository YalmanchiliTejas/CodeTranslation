#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

const int N = 5000001;
long long fact[N];
long long invfact[N];
long long inv[N];
void init() {
        fact[0] = fact[1] = 1;
        for (int i = 2; i < N; i ++) fact[i] = fact[i - 1] * i % MOD;
        inv[1] = 1;
        for (int i = 2; i < N; i ++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        invfact[0] = invfact[1] = 1;
        for (int i = 2; i < N; i ++) invfact[i] = invfact[i - 1] * inv[i] % MOD;
}
long long C(long long n, long long r) {
        if (n < 0 || r < 0 || n < r) return 0;
        return fact[n] * invfact[n - r] % MOD * invfact[r] % MOD;
}

int main() {
        init();
        int n, a, b, c, d;
        scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
        int N = 1010;
        vector<vector<long long>> dp(N, vector<long long> (N));
        dp[1][0] = 1;
        for (int i = 1; i <= b; i ++) {
                for (int j = 0; j <= n; j ++) {
                        (dp[i + 1][j] += dp[i][j]) %= MOD;
                        if (a > i) continue;
                        int rest = n - j;
                        long long coef = 1LL;
                        for (int k = 1; k <= d; k ++) {
                                if (j + k * i > n) break;
                                (coef *= C(rest, i)) %= MOD;
                                rest -= i;
                                if (k >= c) {
                                        long long coef2 = coef * invfact[k] % MOD;
                                        (dp[i + 1][j + k * i] += dp[i][j] * coef2 % MOD) %= MOD;
                                }
                        }
                }
        }
        printf("%lld\n", dp[b + 1][n]);
        return 0;
}


#include <cstdio>
#include <vector>
#include <iostream>

const int N = 1000;
const int MOD = (int)1e9 + 7;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int inverse(int a)
{
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

int binom[N + 1][N + 1], fact[N + 1], inv_fact[N + 1], pow[N + 1][N + 1];

int main()
{
#ifdef LOCAL_JUDGE
    freopen("E.in", "r", stdin);
#endif
    for (int i = 0; i <= N; ++ i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++ j) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
        }
    }
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= N; ++ i) {
        fact[i] = (long long)fact[i - 1] * i % MOD;
        inv_fact[i] = inverse(fact[i]);
    }
    for (int i = 0; i <= N; ++ i) {
        pow[i][0] = 1;
        for (int j = 1; j <= N; ++ j) {
            pow[i][j] = (long long)pow[i][j - 1] * inv_fact[i] % MOD;
        }
    }
    int n, a, b, c, d;
    while (scanf("%d%d%d%d%d", &n, &a, &b, &c, &d) == 5) {
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        for (int size = a; size <= b; ++ size) {
            std::vector<int> new_dp(n + 1);
            for (int i = 0; i <= n; ++ i) {
                update(new_dp[i], dp[i]);
                for (int count = c; count <= d && i + size * count <= n; ++ count) {
                    update(new_dp[i + size * count],
                          (long long)dp[i] * binom[n - i][size * count] % MOD * fact[size * count] % MOD * pow[size][count] % MOD * inv_fact[count] % MOD);
                }
            }
            dp = new_dp;
        }
        printf("%d\n", dp[n]);
    }
}

#include <cstdint>
#include <cstdio>

const int64_t MOD = 998244353;
const int N = 1e7 + 10;
int n;
int64_t fac[N], inv[N], pow2[N];

int64_t pow(int64_t a, int exp) {
    int64_t ret = 1;
    while (exp) {
        if (exp & 1) (ret *= a) %= MOD;
        (a *= a) %= MOD;
        exp >>= 1;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    int64_t a = pow(3, n), b = 0;
    fac[0] = inv[0] = inv[1] = pow2[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;
    for (int i = 2; i < N; i++) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    for (int i = 2; i < N; i++) (inv[i] *= inv[i - 1]) %= MOD;
    for (int i = 1; i < N; i++) pow2[i] = (pow2[i - 1] << 1) % MOD;
    for (int i = n / 2 + 1; i <= n; i++) (b += fac[n] * inv[i] % MOD * inv[n - i] % MOD * pow2[n - i]) %= MOD;
    int64_t ans = ((a - 2 * b) % MOD + MOD) % MOD;
    printf("%ld\n", ans);
    return 0;
}

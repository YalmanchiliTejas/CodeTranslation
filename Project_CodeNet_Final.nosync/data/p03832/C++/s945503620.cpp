#include <bits/stdc++.h>
using i64 = long long;

long long *fact, *inv;

template <typename T, typename U, typename V>
auto pow(T x_, U n_, V mod_) {
    std::common_type_t<T, U, V> ret = 1, x = x_, n = n_, mod = mod_;
    while(n > 0) {
        if ((n & 1) == 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

template <typename T, typename U>
auto inverse(T x, U p) { return pow(x, p - 2, p); }

void init_factorial(int n, long long mod) {
    fact = new long long[n + 1];
    inv = new long long[n + 1];
    fact[0] = 1;
    for (long long i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
    inv[n] = inverse(fact[n], mod);
    for (long long i = n; i > 0; i--) inv[i - 1] = inv[i] * i % mod;
}

int main() {
    constexpr i64 mod = 1000000007;
    int n, a, b, c, d;
    std::cin >> n >> a >> b >> c >> d;
    init_factorial(1010, mod);
    std::vector<i64> dp(1010);
    std::vector<std::vector<i64>> mk(1010, std::vector<i64>(1010));
    for (int i = a; i <= b; i++) {
        mk[i][0] = 1;
        for (int j = 1; j <= d; j++) mk[i][j] = mk[i][j - 1] * inv[i] % mod;
    }
    dp[0] = fact[n];
    for (int i = 0; i <= b - a; i++) {
        int m = a + i;
        std::vector<i64> next(1010);
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j / m; k++) {
                if (c <= k && k <= d) {
                    next[j] = (next[j] + dp[j - k * m] * inv[k] % mod * mk[m][k] % mod) % mod;
                } else {
                    next[j] = dp[j];
                }
            }
        }
        std::swap(dp, next);
    }

    std::cout << dp[n] << std::endl;

    return 0;
}

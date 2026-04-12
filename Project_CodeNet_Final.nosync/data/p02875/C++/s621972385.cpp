#include <bits/stdc++.h>
using i64 = long long;

long long *fact, *inv;

template <typename T, typename U, typename V>
constexpr auto pow(T x_, U n_, V mod_) {
    std::common_type_t<T, U, V> ret = 1, x = x_, n = n_, mod = mod_;
    while(n > 0) {
        if ((n & 1) == 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

template <typename T, typename U>
constexpr auto inverse(T x, U p) { return pow(x, p - 2, p); }

void init_factorial(int n, long long mod) {
    fact = new long long[n + 1];
    inv = new long long[n + 1];
    fact[0] = 1;
    for (long long i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
    inv[n] = inverse(fact[n], mod);
    for (long long i = n; i > 0; i--) inv[i - 1] = inv[i] * i % mod;
}

int main() {
    constexpr i64 mod = 998244353;
    i64 n;
    std::cin >> n;
    i64 m = n / 2;
    init_factorial(m + 1, mod);

    i64 t = 0, ret = 0, two = 1, itwo = pow(2, m - 1, mod);
    constexpr i64 k = inverse(2, mod);
    for (int i = 1; i <= m; i++) {
        t = (t + fact[m] * inv[i - 1] % mod * inv[m - i + 1] % mod * two % mod) % mod;
        ret = (ret + fact[m] * inv[i] % mod * inv[m - i] % mod * itwo % mod * t % mod) % mod;
        two = two * 2 % mod;
        itwo = itwo * k % mod;
    }

    ret = (pow(3, n, mod) + mod - ret * 2 % mod) % mod;

    std::cout << ret << std::endl;

    return 0;
}

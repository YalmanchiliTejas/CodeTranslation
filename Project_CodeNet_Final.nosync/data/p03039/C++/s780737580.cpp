#include <bits/stdc++.h>
using i64 = long long;

long long *fact, *inv;

template <class T>
T pow(T x, T n, T mod) {
    T ret = 1;
    while(n > 0) {
        if ((n & 1) == 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

template <class T>
T inverse(T x, T p) { return pow(x, p - 2, p); }

void init_factorial(int n, long long mod) {
    fact = new long long[n + 1];
    inv = new long long[n + 1];
    fact[0] = 1;
    for (long long i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
    inv[n] = inverse(fact[n], mod);
    for (long long i = n; i > 0; i--) inv[i - 1] = inv[i] * i % mod;
}

int main() {
    i64 n, m, k;
    constexpr i64 mod = 1000000007;
    std::cin >> n >> m >> k;
    init_factorial(n * m, mod);
    i64 co = fact[n * m - 2] * inv[k - 2] % mod * inv[n * m - k] % mod;
    i64 ret = 0;
    for (i64 i = 0; i < n; i++) for (i64 j = 0; j < m; j++) {
        i64 t1 = (i * (i + 1) % mod * inv[2] % mod + (n - i) * (n - 1 - i) % mod * inv[2] % mod) * m % mod;
        i64 t2 = (j * (j + 1) % mod * inv[2] % mod + (m - j) * (m - 1 - j) % mod * inv[2] % mod) * n % mod;
        ret = (ret + t1 + t2) % mod;
    }
    std::cout << ret * co % mod * inv[2] % mod << std::endl;

    return 0;
}

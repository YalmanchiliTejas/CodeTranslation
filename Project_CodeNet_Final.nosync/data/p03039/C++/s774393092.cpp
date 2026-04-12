#include <iostream>

const int mod = 1000000007;
const int kcomb_max = 510000;

long long fact[kcomb_max], fact_inv[kcomb_max], inv[kcomb_max];

void init_comb()
{
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;

    for (int i = 2; i < kcomb_max; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }
}

long long comb(int n, int k)
{
    if (n < k) {
        return 0;
    }
    if (n < 0 || k < 0) {
        return 0;
    }
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) % mod;
}

int main()
{
    init_comb();

    int n, m, k;
    std::cin >> n >> m >> k;

    long long ans = 0;
    long long comb_value = comb(m * n - 2, k - 2);
    for (int x_distance = 1; x_distance < m; x_distance++) {
        ans += ((x_distance * n * n) % mod * ((m - x_distance) * comb_value) % mod) % mod;
        ans %= mod;
    }

    for (int y_distance = 1; y_distance < n; y_distance++) {
        ans += ((y_distance * m * m) % mod * ((n - y_distance) * comb_value) % mod) % mod;
        ans %= mod;
    }

    std::cout << ans << std::endl;
}

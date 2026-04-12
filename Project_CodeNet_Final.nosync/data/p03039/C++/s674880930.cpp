#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

const int mod = 1e9 + 7;
const int kmax = 510000;

long long fact[kmax], fact_inv[kmax], inv[kmax];

void init_comb()
{
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < kmax; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }
}

long long comb(int n, int r)
{
    if (n < r) {
        return 0;
    }

    if (n < 0 || r < 0) {
        return 0;
    }

    return fact[n] * (fact_inv[r] * fact_inv[n - r] % mod) % mod;
}

int main()
{
    init_comb();

    int n, m, k;
    std::cin >> n >> m >> k;

    long long comb_value = comb(n * m - 2, k - 2);
    long long ans = 0;
    for (int x_distance = 1; x_distance < m; x_distance++) {
        ans += (m - x_distance) * n * n % mod * comb_value % mod * x_distance % mod;
        ans %= mod;
    }

    for (int y_distance = 1; y_distance < n; y_distance++) {
        ans += (n - y_distance) * m * m % mod * comb_value % mod * y_distance % mod;
        ans %= mod;
    }

    std::cout << ans << std::endl;
}

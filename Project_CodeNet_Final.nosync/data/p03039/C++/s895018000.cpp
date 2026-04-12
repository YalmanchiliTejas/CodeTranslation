#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main()
{ 
    using i64 = int64_t;
    
    const i64 mod = 1000000000 + 7;

    i64 n, m, k;
    
    cin >> n >> m >> k;
    
    vector<i64> inv(n * m + 1);
    vector<i64> fact(n * m + 1);
    vector<i64> fact_inv(n * m + 1);

    for (i64 i = 1; i < n * m + 1; i++) {
        inv[i] = (i == 1) ? 1 : (mod - (mod / i) * inv[mod % i] % mod);
    }

    fact[0] = 1;
    fact_inv[0] = 1;

    for(int i = 1; i < n * m + 1; ++i) {
        fact[i] = fact[i - 1] * i % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }

    auto comb = [&](int n, int k) {
        if (n < 0 || n < k) {
            return i64(0);
        }

        return fact[n] * fact_inv[n - k] % mod * fact_inv[k] % mod;
    };
    
    i64 ans = 0;
    
    i64 c = comb(n * m - 2, k - 2);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            ans += ((m - j - 1) * (m - j) / 2) % mod * c % mod * n % mod;
            ans %= mod;
            ans += ((n - i - 1) * (n - i) / 2) % mod * c % mod * m % mod;
            ans %= mod;
        }
    }
    
    cout << ans << endl;
}

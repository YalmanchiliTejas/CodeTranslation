#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000 + 7;

const int MAX = 200010;

long long fac[MAX], finv[MAX], inv[MAX];

void comb_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long mod_comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    comb_init();
    long long c;
    if (k == 2) c = 1;
    else  c = mod_comb(n * m - 2, k - 2);

    long long ans = 0;
    for (int d = 1; d <= n - 1; d++)
    {
        ans += (d * (n - d) * m * m) % MOD;
        ans %= MOD;
    }
    for (int d = 1; d <= m - 1; d++)
    {
        ans += (d * (m - d) * n * n) % MOD;
        ans %= MOD;
    }
    
    ans *= c % MOD;
    ans %= MOD;

    cout << ans << endl;
}

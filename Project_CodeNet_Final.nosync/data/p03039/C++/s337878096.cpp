#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define Int int64_t
#define dump(x) cout << (x) << endl
Int mod = 1e9+7;

const Int MAX = 510000;
const Int MOD = 1000000007;

Int fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (Int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
Int COM(Int n, Int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    COMinit();
    Int n, m, k;
    cin >> n >> m >> k;
    Int res = 0;
    Int add = 0;
    for (Int i = 1; i <= n - 1; i++) {
       add += m * m * i * (n - i);
       add %= mod;
    }
    res = (res + add) % mod;
    add = 0;
    for (Int i = 1; i <= m - 1; i++) {
        add += n * n * i * (m - i);
        add %= mod;
    }
    res = (res + add) % mod;
    res *= COM(n * m - 2, k - 2);
    res %= mod;
 /*    dump(res);
    for (Int i = 1; i <= k - 1; i++) {
        res *= i;
        res %= mod;
    } */
    dump(res);
    return 0;
}
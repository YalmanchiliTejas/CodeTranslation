#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

// ####################
//  Calc nCr
// ####################
const lli MAX = 1000000;
const lli MOD = 1000000007;

lli fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void NCRinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
lli NCR(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// ####################
//  Calc nCr END
// ####################

int main() {
    lli n, m, k;
    const lli MOD = 1000000007;

    cin >> n >> m >> k;

    lli ans = 0;
    // X
    for (int i=1; i<m; i++) {
        ans += n * n * (m-i) * i;
        ans %= MOD;
    }

    // Y
    for (int i=1; i<n; i++) {
        ans += m * m * (n-i) * i;
        ans %= MOD;
    }

    if (k > 2) {
        NCRinit();
        //cout << NCR((int)m*n-2, (int)k-2) << endl;
        ans *= NCR(m*n-2, k-2);
        ans %= MOD;
    }

    cout << ans << endl;


    return 0;
}

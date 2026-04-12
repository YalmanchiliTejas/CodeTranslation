#include <bits/stdc++.h>
using namespace std;

const long long MAX = 200010;
const long long MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // 前処理
    COMinit();

    long long n, m, k;
    cin >> n >> m >> k;
    
    long long ans = 0;
    for(int d = 1; d < n; d++){
        long long t = d * (n - d) * m;
        t %= MOD;
        t *= m;
        t %= MOD;
        t *= COM(n * m - 2, k - 2);
        t %= MOD;
        
        ans += t;
        ans %= MOD;
    }

    for(int d = 1; d < m; d++){
        long long t = d * (m - d) * n;
        t %= MOD;
        t *= n;
        t %= MOD;
        t *= COM(n * m - 2, k - 2);
        t %= MOD;

        ans += t;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
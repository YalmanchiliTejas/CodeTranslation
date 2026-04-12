#include <iostream>

using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

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
    long N, M, K;
    cin >> N >> M >> K;

    long ans = 0;
    for(int i=1; i<=M-1; i++){
        ans += (i*(M-i)*N*N)%MOD;
        ans %= MOD;
    }
    for(int i=1; i<=N-1; i++){
        ans += (i*(N-i)*M*M)%MOD;
        ans %= MOD;
    }

    COMinit();

    ans *= COM(M*N-2, K-2)%MOD;

    cout << ans%MOD;

    return 0;
}
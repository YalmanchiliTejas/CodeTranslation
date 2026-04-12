#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

//a^nを計算する
long long modpow(long int a, long int n, long int mod) {
    long int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

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
    COMinit();
    ll N, M, K; cin >> N >> M >> K;
    ll ans = 0;
    ll MOD_ = COM(N*M-2,K-2);

    for(int i = 1; i < N; i++){
        ll temp = (N-i)*M*M*i;
        ans += temp;
        ans %= MOD;
    }

    for(int i = 1; i < M; i++){
        ll temp = (M-i)*N*N*i;
        ans += temp;
        ans %= MOD;
    }
    cout << (ans*MOD_)%MOD << endl;

}
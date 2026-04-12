#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll N, M, K;

const int MAX = 2 * 1e5;
const int MOD = 1e9 + 7;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
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
    cin >> N >> M >> K;

    COMinit();
    ll ans = 0;
    for(int i=0;i<M;i++){
        ll res = (ll) (M - i) * N * N * i % MOD;
        ans = (ans + res) % MOD;
    }
    for(int i=0;i<N;i++){
        ll res = (ll) (N - i) * M * M * i % MOD;
        ans = (ans + res) % MOD;
    }
    ans = ans * COM(N * M - 2, K - 2) % MOD;

    cout << ans << endl;
}

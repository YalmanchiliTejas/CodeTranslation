#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

const int MAX = 500001;

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

int main()
{
    ll n,m,k;
    cin >> n >> m >> k;
    ll ans = 0;
    COMinit();
    for(ll i = 1; i < n; i++) (ans += i * m * m * (n-i) * COM(n*m-2, k-2)) %= MOD;
    for(ll i = 1; i < m; i++) (ans += i * n * n * (m-i) * COM(n*m-2, k-2)) %= MOD;
    cout << (ans + MOD) % MOD << endl;
}
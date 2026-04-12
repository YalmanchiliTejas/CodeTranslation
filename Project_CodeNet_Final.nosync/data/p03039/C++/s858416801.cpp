#include<bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

using ll = long long;
using LL = long long;

class Edge{
public:
    int from,to;
    ll value, konzatu;
    Edge(int a,int b,ll c, ll d){
        from = a;
        to = b;
        value = c;
        konzatu = d;
    }
    Edge(LL a,LL b,LL c){
        from = a;
        to = b;
        value = c;
    }
    Edge(LL a,LL b){
        from = a;
        to = b;
    }
};

ll mod = 1e9+7;

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

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    ll ans = 0;
    COMinit();

    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            ll a = i;
            ll b = (N - i - 1);
            ll c = j;
            ll d = (M - j - 1);
            ans += M * ((a * (a + 1)) / 2 + (b * (b + 1)) / 2);
            ans += N * ((c * (c + 1)) / 2 + (d * (d + 1)) / 2);
            ans %= mod;
        }
    }
    ans *= modinv(2, mod);
    ans %= mod;
    cout<<(ans * COM(N * M - 2, K - 2)) % MOD<<endl;
}

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

long long fac[510000], finv[510000], inv[510000];

void c4_init(ll m){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < 510000; i++){
        fac[i] = fac[i - 1] * i % m;
        inv[i] = m - inv[m%i] * (m / i) % m;
        finv[i] = finv[i - 1] * inv[i] % m;
    }
}

ll c4(ll n,ll k,ll m){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % m) % m;
}

const ll MOD=1000000007;

// Xについてのみとく。あとで、NとMを入れ替えればYについても計算できる
//
// sigma_全ての組み合わせ sigma_i sigma_j |x_i - x_j| 
// => sigma_i sigma_j sigma_全ての組み合わせ |x_i - x_j| 

signed main() {
    ll N,M,K;
    c4_init(MOD);
    cin>>N>>M>>K;
    ll x=0, y=0;

    for (ll len=1; len<N; len++) {
        x += (((((len * (N-len))%MOD) * M)%MOD) * M)%MOD;
        x %= MOD;
    }

    for (ll len=1; len<M; len++) {
        y += (((((len * (M-len))%MOD) * N)%MOD) * N)%MOD;
        y %= MOD;
    }

    cout<<
        (((x+y)%MOD)*c4(N*M-2,K-2,MOD))%MOD
        <<endl;
    return 0;
}

#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
const int MAX = 1000000;
long long fac[MAX], finv[MAX], inv[MAX];

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

// 二項係数
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    COMinit();
    ll n,m,k;
    cin >> n >> m >> k;
    ll D = 0;
    for(ll i=1;i<n;i++){
        D += (((i*m) % MOD) * (((n-i)*m) % MOD))%MOD;
        D %= MOD;
    }
    for(ll i=1;i<m;i++){
        D += (((i*n) % MOD) * (((m-i)*n) % MOD))%MOD;
        D %= MOD;
    }
    ll ans = (D * COM(n*m-2,k-2))%MOD;
    cout << ans << endl;
    return 0;
}

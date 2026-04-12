#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX = 510000;
const ll mod = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

//mod mでの a の逆元を求める
long long modinv(long long a) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod; 
    if (u < 0) u += mod;
    return u;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    ll n,m,k;
    cin>>n>>m>>k;
    COMinit();
    ll ans = 0;
    for(ll i=0;i<m;i++){
        ll ret = COM(n*m-2,k-2) * n;
        ret %= mod;
        ll sum = (m-1-i) * (m-i) / 2;
        sum %= mod;
        sum += (i*(i+1)/2)%mod;
        sum %= mod;
        sum *= n;
        sum %= mod;
        ret *= sum;
        ret %= mod;
        ans += ret;
        ans %= mod;
    }
    for(ll i=0;i<n;i++){
        ll ret = COM(n*m-2,k-2) * m;
        ret %= mod;
        ll sum = (n-1-i) * (n-i) / 2;
        sum %= mod;
        sum += (i*(i+1)/2)%mod;
        sum %= mod;
        sum *= m;
        sum %= mod;
        ret *= sum;
        ret %= mod;
        ans += ret;
        ans %= mod;
    }
    ans *= modinv(2);
    ans %= mod;
    cout << ans << endl;
    
}
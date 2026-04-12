#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

constexpr ll mod = 1000000000 + 7;
#define NMAX 200010
ll fac[NMAX];
ll inv[NMAX];

ll mod_pow(ll a, ll n, ll mod){
    ll ret = 1;
    while(n > 0){
        if(n & 1) ret = (ret*(a % mod))%mod;
        a = ((a%mod)*(a%mod)) % mod;
        n = n >> 1;
    }
    return ret;
}

ll mod_inv(ll a, ll mod){
    return mod_pow(a, mod-2, mod);
}

void mae_nck(){
    fac[1] = 1;
    inv[1] = 1;
    for(ll i = 2; i < NMAX; i++){
        fac[i] = (fac[i-1] * i)%mod;
        inv[i] = (inv[i-1] * mod_inv(i, mod))%mod;
    }
}

ll mod_nck(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    if(k == 0 || k == n) return 1;
    ll ret = ((fac[n] * inv[k])%mod * inv[n-k])%mod;
    return ret;
}
int main(){

    // pre-processing
    mae_nck();

    // input
    ll n, m, k;
    cin >> n >> m >> k;

    ll coeff = mod_nck(n * m - 2, k - 2);
    ll ans = 0;
    rep(i, 0, m-1){
        ll cm = m - i;
        ll cur = (cm * (cm - 1) / 2) % mod * (n * n) % mod;
        ans += cur % mod;
        ans %= mod;
    }
    rep(i, 0, n-1){
        ll cm = n - i;
        ll cur = (cm * (cm - 1) / 2) % mod * (m * m) % mod;
        ans += cur % mod;
        ans %= mod;
    }
    ans *= coeff;
    ans %= mod;
    cout << ans << endl;
    return 0;
}
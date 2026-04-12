#include <bits/stdc++.h>
using namespace std;
#define ll long long



ll modpower(ll a, ll r, ll mod){ //a^r
    ll x = 1;
    a %= mod;
    while (r > 0) {
        if (r & 1) x = x * a % mod;
        r >>= 1;
        a = a * a % mod;
    }
    return x;
}

ll modinv(ll a, ll mod){
    return modpower(a, mod-2, mod);
}

vector<ll> fact;
vector<ll> invfact;

void set_fact(ll n, ll mod){
    fact.resize(n+1, 1);
    invfact.resize(n+1, 1);
    for (ll i = 2; i <= n; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    invfact[n] = modinv(fact[n], mod);
    for (ll i = n-1; i >= 2; i--) {
        invfact[i] = invfact[i+1] * (i+1) % mod;
    }
    return;
}

ll comb(ll n, ll k, ll mod) {
    if (k > n || k < 0) return 0;
    if (k == n || k == 0) return 1;
    return fact[n] * invfact[n-k] % mod * invfact[k] % mod;
}


int main() {
    ll N;
    cin >> N;
    ll mod = 998244353;
    ll all = modpower(3, N, mod);
    ll ex = 0;
    set_fact(N+2, mod);
    
    vector<ll> pow2(N+1, 1);
    for (ll i = 1; i <= N; i++) pow2[i] = pow2[i-1]*2%mod;
    for (ll i = N/2+1; i <= N; i++) {
        ex += 2LL * comb(N, i, mod) * pow2[N-i] % mod;
        ex %= mod;
    }
    cout << (all+mod-ex)%mod << endl;
    return 0;
}
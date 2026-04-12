#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;
ll fact[210200];
ll invfact[210200];

inline ll take_mod(ll a){
    return (a % mod + mod) % mod;
}

inline ll add(ll a, ll b){
    return take_mod(a+b);
}

inline ll sub(ll a, ll b){
    return take_mod(a-b);
}


inline ll mul(ll a, ll b){
    return take_mod(a * b);
}

inline ll pow(ll x, ll n){
    ll res = 1LL;
    while(n > 0){
        if(n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return pow(x, mod-2);
}

// nは上限
void make_fact(ll n){
    fact[0] = 1;
    ll res = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = res;
        res = mul(res, i+1);
    }
}

// nは上限
void make_invfact(ll n){
    invfact[0] = 1;
    invfact[n] = mod_inv(fact[n]);
    for(int i = n-1; i >= 1; i--){
        invfact[i] = mul(invfact[i + 1], i + 1);
    }
}

ll perm(ll n, ll k){
    return mul(fact[n], invfact[n-k]);
}

ll comb(ll n, ll k){
    if(k == 0){
        return 1;
    }
    return mul(mul(fact[n], invfact[n-k]), invfact[k]);
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    make_fact(210000);
    make_invfact(210000);

    ll res = mul(m, mul(m, mul(n, mul(n-1, mul(n+1, mod_inv(6))))));
    res = add(res, mul(n, mul(n, mul(m, mul(m-1, mul(m+1, mod_inv(6)))))));
    res = mul(res, comb(sub(mul(n, m), 2), sub(k, 2)));

    cout << res << endl;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll fast_pow(ll a, ll b, ll p){
    ll ans = 1;
    ll base = a % p;
    b = b % (p - 1);
    
    while(b){
        if (b & 1)
            ans = (ans * base) % p;
        
        base = (base * base) % p;
        b >>= 1;
    }

    return ans;
}

ll inv(ll a, ll p){
    return fast_pow(a, p - 2, p);
}

ll C(ll n, ll m, ll p){
    if (n < m)
        return 0;

    m = min(m, n - m);
    
    ll nom = 1, den = 1;
    for (ll i = 1; i <= m; i++){
        nom = (nom * (n - i + 1)) % p;
        den = (den * i) % p;
    }

    return (nom * inv(den, p)) % p;
}

ll lucas(ll n, ll m, ll p){
    if (m == 0)
        return 1;
    return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m, k;
    cin >> n >> m >> k;

    ll ans = 0;
    for (ll i = 1; i < n; i++){
        ans += ((((((n - i) * i) % MOD) * m) % MOD) * m) % MOD;
        ans %= MOD;
    }

    for (ll i = 1; i < m; i++){
        ans += ((((((m - i) * i) % MOD) * n) % MOD) * n) % MOD;
        ans %= MOD;
    }
    
    cout << (ans * lucas(n * m - 2, k - 2, MOD)) % MOD << '\n';

    return 0;
}

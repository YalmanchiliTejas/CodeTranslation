#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const ll mod = (ll)1e9 + 7;

int n, m, k;
ll fac[N], facinv[N];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll ginv(ll x) {
    return fp(x, mod - 2);
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

ll sum(ll len) {
    return (len + 1) * len % mod * inv[2] % mod;
}

int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    cin >> n >> m >> k;
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        ll denom = m * inv[n * m - 1] % mod;
        res += inv[n] * denom % mod * (sum(i - 1) + sum(n - i)) % mod;
        res %= mod;
    }
//    cout << res << endl;
    for(int i = 1; i <= m; i++) {
        ll denom = n * inv[n * m - 1] % mod;
        res += inv[m] * denom % mod * (sum(i - 1) + sum(m - i)) % mod;
        res %= mod;
    }
    res = comb(n * m, k) % mod * k % mod * (k - 1) % mod * inv[2] % mod * res % mod;
    res = (res % mod + mod) % mod;
    cout << res << endl;

}

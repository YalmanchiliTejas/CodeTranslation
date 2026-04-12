#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e7 + 50;
const ll mod = 998244353;

int n;
ll fac[N], facinv[N];
ll inv[N], pw[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

void init_fac() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
    pw[0] = 1;
    for(int i = 1; i < N; i++) pw[i] = pw[i-1] * 2 % mod;
}

ll ssum[N];


int main(){
    init_fac();
    cin >> n;
    n /= 2;
    for(int i = n; i >= 1; i--) {
        ssum[i] = (comb(n, i) * pw[n - i] + ssum[i+1]) % mod;
    }
    ll comp = 0;
    for(int i = 0; i <= n; i++) {
        comp += comb(n, i) * pw[i] % mod * ssum[i+1] % mod;
        comp %= mod;
    }
    ll res = 1;
    for(int i = 0; i < n; i++) res = (res * 9) % mod;
    cout << ((res - comp * 2) % mod + mod) % mod << endl;
}

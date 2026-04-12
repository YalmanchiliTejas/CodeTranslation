#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3005;
const ll mod = (ll)1e9 + 7;

int n, a, b, c, d;
ll fac[N], facinv[N];
ll inv[N];
ll dp[N][N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

ll get(int i, int rem) {
    if(i < a) return rem == 0;
    if(dp[i][rem] != -1) return dp[i][rem];
    dp[i][rem] = 0;
    for(int j = c; j <= min(d, rem / i); j++) {
        dp[i][rem] += get(i - 1, rem - j * i) *
                comb(rem, j * i) % mod * fac[j * i] % mod * fp(facinv[i], j) % mod * facinv[j] % mod;
    }
    dp[i][rem] += get(i - 1, rem);
    dp[i][rem] %= mod;
    return dp[i][rem];
}


int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    memset(dp, -1, sizeof(dp));
    cin >> n >> a >> b >> c >> d;
    cout << get(b, n) << endl;

}

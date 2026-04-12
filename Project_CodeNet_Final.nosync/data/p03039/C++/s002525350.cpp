#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
const int MOD = 1e9 + 7;
void add(ll& x, ll y) {
    x += y;
    x %= MOD;
}
ll qpow(ll x, ll k) {
    ll r = 1;
    while(k) {
        if(k & 1) r = r * x % MOD;
        k >>= 1;
        x = x * x % MOD;
    }
    return r;
}
ll d[N];
ll C(int i, int j) {
    return d[i] * qpow(d[i-j], MOD-2) % MOD * qpow(d[j], MOD - 2) % MOD;
}
ll sum(ll n) {
    return n*(n+1)/2;
}
int main() {
    d[0] = 1;
    for(int i = 1; i < N; i++) {
        d[i] = d[i-1] * i % MOD;
    }
    ll ans = 0;
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ll tmp = C(n*m-2, k-2);
            ll x = (sum(m-j) + sum(j-1))*n%MOD;
            ll y = (sum(n-i) + sum(i-1))*m%MOD;
            ans += (x+y)*tmp%MOD;
            ans %= MOD;
        }
    }
    cout << ans*qpow(2,MOD-2)%MOD << '\n';
    return 0;
}
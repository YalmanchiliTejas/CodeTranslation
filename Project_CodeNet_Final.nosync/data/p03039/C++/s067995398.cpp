#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll pl(ll a, ll b) {
    a %= mod, b %= mod;
    return (a+b) % mod;
}
ll mu(ll a, ll b) {
    a %= mod, b %= mod;
    return (a*b) % mod;
}
ll pow_mod(ll a, ll b) {
    if (b == 0) return 1;
    ll k = pow_mod(a, b/2);
    k = mu(k, k);
    if (b & 1) k = mu(k, a);
    return k;
}
ll di(ll a, ll b) {
    return mu(a, pow_mod(b, mod-2));
}
ll nCk(ll n, ll k) {
    ll X = 1, Y = 1;
    for (int a = n, b = k; b > 0; a--, b--) {
        X = mu(X, a);
        Y = mu(Y, b);
    }
    return di(X, Y);
}
int main () {
    ll p, q, K;
    cin >> p >> q >> K;
    ll ans = 0;
    for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= q-1; i++) {
            ans += mu(mu(mu(p, p), q-i), i);
        }
        swap(p, q);
    }
    ans = di(ans, nCk(p*q, 2));
    ans = mu(ans, nCk(p*q, K));
    ans = mu(ans, nCk(K, 2));
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    ll f, r;
    f = r = 0;
    ll p, p2;
    p = p2 = x;
    for (ll i = 0; i < 2*m; ++i) {
        (p *= p) %= m;
        (p2 *= p2) %= m;
        (p2 *= p2) %= m;
        if (p == p2) break;
    }
    ll sf = 0;
    p = x;
    while (p != p2) {
        sf += p;
        (p *= p) %= m;
        (p2 *= p2) %= m;
        ++f;
    }
    ll sr = p;
    (p *= p) %= m;
    ++r;
    while (p != p2) {
        sr += p;
        (p *= p) %= m;
        ++r;
    }
    ll ans = 0;
    if (n <= f) {
        ll tp = x;
        ans = tp;
        for (ll i = 0; i < n-1; ++i) {
            (tp *= tp) %= m;
            ans += tp;
        }
    } else {
        ans = sf;
        ll a = (n - f) / r;
        ll b = n - f - a*r;
        ans += a * sr;
        for (ll i = 0; i < b; ++i) {
            ans += p2;
            (p2 *= p2) %= m;
        }
    }
    cout << ans << endl;
}
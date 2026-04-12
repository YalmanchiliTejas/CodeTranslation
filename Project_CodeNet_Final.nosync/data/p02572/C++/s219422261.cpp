#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll      = long long;
const int mod = 1000000007;
int main() {
    ll n, r = 0, s = 0, t = 0;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll& i : a) cin >> i, (s += i) %= mod;
    for (int i = 0; i < n; ++i) (r += a[i] * s % mod) %= mod;
    for (int i = 0; i < n; ++i) (t += a[i] * a[i] % mod) %= mod;
    cout << ((r - t + mod) % mod * 500000004) % mod;
}
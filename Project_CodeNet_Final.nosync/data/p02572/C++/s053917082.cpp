#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    ll s = 0, r = 0;
    vector<ll> a(n);
    for (ll &i : a) {
        cin >> i; s += i;
    }
    s %= mod;
    for (ll i : a) {
        s -= i;
        s %= mod;
        r += s * i;
        r %= mod;
    }
    cout << (r + mod) % mod << endl;
    return 0;
}


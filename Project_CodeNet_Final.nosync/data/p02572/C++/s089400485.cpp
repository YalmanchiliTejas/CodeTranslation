#include <bits/stdc++.h>

#define pb push_back
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

int pow(int n, int x) {
    ll res = 1;
    while (n) {
        if (n & 1) res = (res * x) % mod;
        x = ((ll)x * x) % mod;
        n >>= 1;
    }
    return res;
}

int inv(int x) { return pow(mod - 2, x); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    for (int T = 0; T < t; T++) {
        ll n;
        cin >> n;
        ll a[n], sum = 0, sqsum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            sqsum += ((a[i] * a[i]) % mod);
            sum %= mod;
            sqsum %= mod;
        }
        ll ans = (((sum * sum) % mod - sqsum % mod + mod)) % mod;
        cout << ans * (ll)inv(2) % mod << endl;
    }
    return 0;
}

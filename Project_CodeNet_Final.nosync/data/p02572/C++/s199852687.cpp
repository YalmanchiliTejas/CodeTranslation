#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a[n];
    rep(i, n) { cin >> a[i]; }
    ll b[n];
    b[0] = a[0];
    repd(i, 1, n) {
        b[i] = b[i - 1] + a[i];
        b[i] %= mod;
    }

    ll ans = 0;
    repd(i, 1, n) {
        ans += a[i] * b[i - 1];
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}


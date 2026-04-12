#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, n) for (ll i = n-1; i >= 0; i--)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define repd2(i, s, n) for (ll i = n-1; i >= (s); i--)

int main() {
    const ll MOD = 1000000007;
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> b(n);
    b = a;
    ll ans = 0;
    rep2(i, 1, n) b[i] += b[i-1];
    rep(i, n) {
        ans += (a[i]%MOD)*((b[n-1]-b[i])%MOD);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
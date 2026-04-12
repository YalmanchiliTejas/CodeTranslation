#include <iostream>
using namespace std;
using ll = long long;
const ll M = 998244353;
ll dp[3010];
signed main() {
    ll n, s;
    cin >> n >> s;
    ll x = 0;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        (dp[0] += 1) %= M;
        for (ll v = s; v >= a; v--) {
            (dp[v] += dp[v - a]) %= M;
        }
        (x += dp[s]) %= M;
    }
    cout << x << endl;
}

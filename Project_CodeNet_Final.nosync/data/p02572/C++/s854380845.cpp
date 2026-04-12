#include <bits/stdc++.h>
typedef long long ll;
const int inf = 1e9;
using namespace std;
const ll mod = 1e9+7;





int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 1; i <= n; i++) cin >> a[i];

    ll ans = 0;
    ll s = 0;
    for(int i = 1; i <= n; i++){
        ans += s*a[i];
        s += a[i];
        s %= mod;
        ans %= mod;
    }
    cout << ans << '\n';

    return 0;
}

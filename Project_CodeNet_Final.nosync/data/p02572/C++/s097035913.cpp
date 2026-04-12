/* インクルードなど */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = pow(10, 9) + 7;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n+1,0);
    for (ll i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (ll i = 0; i < n; i++) {
        b[i+1] = b[i] + a[i];
    }
    ll ans = 0;
    for (ll i = 0; i < n-1; i++) {
        ans += a[i] * ((b[n] - b[i+1]) % MOD);
        ans %= MOD;
    }
    cout << ans << endl;
}
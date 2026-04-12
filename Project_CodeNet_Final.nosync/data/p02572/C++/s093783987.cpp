#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
const int mod = 1e9 + 7;


int main() {
    int n; cin >> n;
    V<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    V<ll> w(n + 1);
    for(int i = 0; i < n; i++){
        w[i + 1] = (w[i] + v[i]);
    }

    ll ans = 0;
    for(int i = 0; i < n - 1; i++){
        ans += (w[n] - w[i + 1]) % mod * v[i] % mod;
        ans %= mod;
    }
    cout << ans << endl;



    return 0;
}

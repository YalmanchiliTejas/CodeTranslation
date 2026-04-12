#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long mod = 1000000007L;

int main() {
    int n;
    cin >> n;

    ll a[n+10];
    ll sum = 0;
    rep (i, n) {
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        sum -= a[i];
        sum %= mod;
        ans += a[i] * sum;
        ans %= mod;
    }
    
    if (ans < 0) cout << ans + mod << endl;
    else cout << ans % mod << endl;
    return 0;
    
    
}
#include "bits/stdc++.h"
using namespace std; 

#ifdef LOCAL
    #include "debug.h"
    #define input freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
    #define debug(...) 4
    #define input 4
#endif

using ll = long long;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;


signed main() {
    input;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        sum -= a[i];
        ans += ((a[i] % mod) * (sum % mod)) % mod;
        ans %= mod;

    }
    cout << ans << "\n";
    

}
  


#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define bg(x) (x).begin()
#define ed(x) (x).end()
#define ar array
#define ll long long int

const ll mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
      ll n;
      cin >> n;
      vector<ll> a(n);
      for (ll &x : a)
        cin >> x;
      ll ans = 0;
      ll suffix = 0;

      for (int j = n - 1; j >= 0; --j) {
          ll f  = (a[j] * suffix) % mod;
          ans = (ans + f) % mod;
          suffix = (suffix + a[j]) % mod;
      }
      cout << ans;
    }

    return 0;
}
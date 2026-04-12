    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using ld = long double;
     
    signed main() {
    #ifdef LOCAL
      assert(freopen("a.in", "r", stdin));
    #endif
      ll k, a, b;
      cin >> k >> a >> b;
      if (a >= k) {
        cout << 1 << '\n';
        return 0;
      }
      if (b >= a) {
        cout << -1 << '\n';
        return 0;
      }
      k -= a;
      ll d = a - b;
      cout << 1 + 2 * ((k + d - 1) / d) << '\n';
    }
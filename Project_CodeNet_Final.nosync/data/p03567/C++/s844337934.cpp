#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  string s;
  cin >> s;
  for (int i = 0; i < int(s.size()) - 1; ++i) {
    if (s.substr(i, 2) == "AC") {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
}
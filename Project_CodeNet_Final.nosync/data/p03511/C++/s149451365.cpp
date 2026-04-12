#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int l;
  cin >> l;
  string s, t;
  cin >> s >> t;
  int n = (int) s.size(), m = (int) t.size();
  string ans = "{";
  auto make = [] (int x, string s) -> string {
    string res;
    for (int i = 0; i < x; i++) res += s;
    return res;
  };
  for (int i = 0; i * n <= l; i++) {
    if ((l - i * n) % m == 0) {
      ans = min(ans, make(i, s) + make((l - i * n) / m, t));
      ans = min(ans, make((l - i * n) / m, t) + make(i, s));
      break;
    }
  }
  for (int i = l / n; i >= 0; i--) {
    if ((l - i * n) % m == 0) {
      ans = min(ans, make(i, s) + make((l - i * n) / m, t));
      ans = min(ans, make((l - i * n) / m, t) + make(i, s));
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
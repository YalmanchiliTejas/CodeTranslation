#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  int s, t;
  int p, q, m;
  int y;
  cin >> s >> t >> p >> q >> m >> y;
  cout << (y ^ s ^ t) << '\n';
  return 0;
}

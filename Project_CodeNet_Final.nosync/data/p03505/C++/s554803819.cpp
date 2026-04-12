#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint k, a, b; cin >> k >> a >> b;
  if (a >= k) {
    return cout << 1 << '\n', 0;
  }
  if (a <= b) {
    return cout << -1 << '\n', 0;
  }
  lint d = a - b;
  lint res = (max(k - a, 0LL) + d - 1) / d;
  res = 2 * res + 1;
  cout << res << '\n';
}
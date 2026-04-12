#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


lint rec(int n, lint x) {
  lint m = (1LL << n + 2) - 3;
  assert(0 < x and x <= m);
  if (!n) {
    return 1;
  }
  if (x == 1) return 0;
  if (x <= m - 1 >> 1) {
    return rec(n - 1, x - 1);
  }
  x -= m - 1 >> 1;
  lint res = (1LL << n) - 1;
  if (x == 1) return res + 1;
  if (x == m + 1 >> 1) return 2 * res + 1;
  return res + 1 + rec(n - 1, x - 1);
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  lint x; cin >> x;
  cout << rec(n, x) << '\n';
}
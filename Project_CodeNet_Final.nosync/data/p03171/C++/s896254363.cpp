#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


constexpr lint inf = 9e18;

int n;
V<> a;

lint mn(int l, int r);
lint mx(int l, int r);

VV<lint> _mn;
lint mn(int l, int r) {
  if (l > r) return 0;
  if (_mn[l][r] != inf) return _mn[l][r];
  return _mn[l][r] = min(mx(l + 1, r) - a[l], mx(l, r - 1) - a[r]);
}

VV<lint> _mx;
lint mx(int l, int r) {
  if (l > r) return 0;
  if (_mx[l][r] != -inf) return _mx[l][r];
  return _mx[l][r] = max(a[l] + mn(l + 1, r), a[r] + mn(l, r - 1));
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  cin >> n;
  a.resize(n);
  assign(_mn, n, n, inf);
  assign(_mx, n, n, -inf);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << mx(0, n - 1) << '\n';
}
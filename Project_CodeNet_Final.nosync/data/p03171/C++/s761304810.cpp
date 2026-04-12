// 26
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fors(_, x, n, s) \
  for (int _ = x; _ < n; _ += s)
#define forn(_, x, n) fors(_, x, n, 1)
#define rep(_, n) forn(_, 0, n)
#define forrs(_, x, n, s) \
  for (int _ = x; _ > n; _ -= s)
#define forrn(_, x, n) forrs(_, x, n, 1)
#define rrep(_, n) forrn(_, n - 1, -1)
#define fi first
#define se second
#define pb push_back
#define pairii pair<int, int>
#define all(x) x.begin(), x.end()
#define lli __int128_t
#define li long long int
#define ld long double
#ifdef LOCAL
#define debug(e)                             \
  cerr << "\033[48;5;196m\033[38;5;15m" << e \
       << "\033[0m";
#else
#define debug(e)
#endif
// 4
template <class A, class B>
ostream &operator<<(ostream &os, pair<A, B> &p) {
  return os << "(" << p.fi << " " << p.se << ")";
}
// 8
template <class T>
ostream &operator<<(ostream &os, vector<T> &v) {
  rep(i, (int)v.size()) os << setw(7) << left << v[i];
  return os << endl;
}
// 5
template <class A, class B>
ostream &operator<<(ostream &os, map<A, B> &m) {
  for (auto &kv : m) os << kv;
  return os;
}
// 3
const li inf = 1e18;
void _main(int tc) {
  int n;
  cin >> n;
  vector<li> v(n);
  rep(i, n) cin >> v[i];
  vector<vector<li>> mem(n, vector<li>(n, -inf));
  function<li(int, int)> f = [&](int l, int r) -> li {
    if (r == l) return v[l];
    if (mem[l][r] != -inf) return mem[l][r];
    return mem[l][r] = max(v[l] - f(l + 1, r), v[r] - f(l, r - 1));
  };
  cout << f(0, n - 1) << endl;
}
// 7
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0), exit(0);
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}
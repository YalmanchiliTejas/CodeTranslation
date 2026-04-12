// 27
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
#define len(x) int(x.size())
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
ostream &operator<<(ostream &o, const pair<A, B> &p) {
  return o << "(" << p.fi << " " << p.se << ")";
}
// 8
template <class T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  rep(i, (int)v.size()) o << setw(7) << left << v[i];
  return o << endl;
}
// 5
template <class A, class B>
ostream &operator<<(ostream &o, const map<A, B> &m) {
  for (auto &kv : m) o << kv;
  return o;
}
// 3
void _main(int tc) {
  char c;
  cin >> c;
  if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
}
// 7
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0), exit(0);
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}
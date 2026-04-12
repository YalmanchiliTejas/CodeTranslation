#include <bits/stdc++.h>
using namespace std;
#define BIT(n) (1LL << (n))
#define BITF(n, i) (((n) >> (i)) & 1)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define REPI(i, x) for (int i = 1; i <= x; i++)
#define FORI(i, m, n) for (int i = m; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define REPZ(i, x) for (int i = 0; i <= x; i++)
#define FORA(i, n) for (auto &&i : n)
#define POW(a, b) ((int)(pow(a, b) + .5))
#define MODULO(a, b) (((a) % (b)) < 0 ? (a) % (b) + (b) : (a) % (b))
#define DUMPOUT cerr
// vector
template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
  for (T &x : vec) is >> x;
  return is;
}
// pair
template <typename T, typename U> ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
// vector
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "{";
  REP(i, (int)vec.size())
  os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
  os << "}";
  return os;
}
// map
template <typename T, typename U> ostream &operator<<(ostream &os, map<T, U> &map_var) {
  os << "{";
  FORA(itr, map_var) {
    os << *itr;
    itr++;
    if (itr != map_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
// set
template <typename T> ostream &operator<<(ostream &os, set<T> &set_var) {
  os << "{";
  FORA(itr, set_var) {
    os << *itr;
    itr++;
    if (itr != set_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) {
  DUMPOUT << head;
  if (sizeof...(Tail) > 0) DUMPOUT << ", ";
  dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define DUMP(...)                                                             \
  DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                             \
          << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" << endl \
          << "    ",                                                          \
      dump_func(__VA_ARGS__)
#define PRINTARR(x, y)                                     \
  cerr << #x << "=\n";                                     \
  for (auto itr = x; itr != y; itr++) cerr << *itr << " "; \
  cerr << endl;
#define PRINTARR2(x, i0, i1)                                       \
  cerr << #x << "=\n";                                             \
  for (int ii0 = 0; ii0 < i0; ii0++) {                             \
    for (int ii1 = 0; ii1 < i1; ii1++) cerr << x[ii0][ii1] << " "; \
    cerr << endl;                                                  \
  }
#else
#define DEB if (false)
#define DUMP(...)
#define PRINTARR(x, y)
#define PRINTARR2(x, i0, i1)
#endif
#define ALL(v) v.begin(), v.end()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define epb emplace_back
#define int long long
#define pint pair<int, int>
#define pdouble pair<double, double>
#define ld long double
using namespace std;
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> using vec = std::vector<T>;
template <class T> void print(const T &x) { cout << x << "\n"; }
const int MOD = 1000000007, INF0 = 1061109567, INF = INF0 * INF0;
const double EPS = 1e-7, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
/*  set UnionFind BIT deque queue multiset segtree priority_queue bitset map vector
[&] { return; }();下のスラッシュを2つ追加しただけ.上のスラッシュを2つにすれば外れる.
//*/
#define MAXN 200100
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);
  string S;
  cin >> S;
  if (S == "AAA" || S == "BBB") {
    print("No");
  } else {
    print("Yes");
  }
}
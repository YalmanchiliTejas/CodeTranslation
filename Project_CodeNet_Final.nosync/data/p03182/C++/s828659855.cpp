#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (long long i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (long long i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) begin(obj), end(obj)
#define RALL(obj) rbegin(obj), rend(obj)
#define fi first
#define se second
using ii = pair<int, int>;
vector<ii> dirs = {
  {1, 0}, {0, 1}, {-1, 0}, {0, -1},  // 4方向
  {1, 1}, {-1, 1}, {-1, -1}, {1, -1},  // 斜め
  {0, 0},  // 自身
};
template <class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

// debug
template <class T> ostream& operator<<(ostream &s, vector<T>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : " "); return s; }
template <class T> ostream& operator<<(ostream &s, vector<vector<T>>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : "\n"); return s; }
template <class T, class S> ostream& operator<<(ostream &s, pair<T, S>& p) { s << "{" << p.first << ", " << p.second << "}"; return s; }
template <class T, class S> ostream& operator<<(ostream& s, map<T, S> m) { for (auto it = m.begin(); it != m.end(); it++) { s << *it << (next(it) == m.end() ? "" : "\n"); } return s; }
#ifdef _MY_DEBUG
  #define dump(...) cerr << "/* " << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl, dump_func(__VA_ARGS__), cerr << "*/\n\n";
#else
  #define dump(...)
  #define endl "\n"
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) { cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...); }

struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
constexpr int MOD = 1000000007;
// *************** TEMPLATE END *************** 

// T0: 元の配列のモノイド
// T1: T0に対する作用素モノイド
template <class T0, class T1>
class SegmentTree {
  // k番目のノードにのlazyを伝搬
  void eval(int k, int len) {
    // u1が正確に単位元ならいらない
    // if (lazy[k] == u1) return;
    // len個分のlazy[k]を評価
    node[k] = g(node[k], p(lazy[k], len));
    if (k < N - 1) {
      // 最下段でなければ下のlazyに伝搬
      lazy[2 * k + 1] = f1(lazy[2 * k + 1], lazy[k]);
      lazy[2 * k + 2] = f1(lazy[2 * k + 2], lazy[k]);
    }
    lazy[k] = u1;
  }
  // k番目のノード[l, r)について、[a, b)の範囲内にxを作用
  void update(int a, int b, T1 x, int k, int l, int r) {
    eval(k, r - l);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] = f1(lazy[k], x);
      eval(k, r - l);
    } else {
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = f0(node[2 * k + 1], node[2 * k + 2]);
    }
  }
  // k番目のノード[l, r)について、[a, b)のクエリを求める
  T0 query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return u0;
    eval(k, r - l);
    if (a <= l && r <= b) return node[k];
    T0 vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    T0 vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return f0(vl, vr);
  }
public:
  int sz; // 元の配列のサイズ
  int N;
  vector<T0> node;
  vector<T1> lazy;
  // T0上の演算、単位元
  using F0 = function<T0(T0, T0)>;
  F0 f0; T0 u0;
  // T1上の演算、単位元
  using F1 = function<T1(T1, T1)>;
  F1 f1; T1 u1;
  // 作用
  using G = function<T0(T0, T1)>;
  G g;
  // 多数のt1(T1)に対するf1の合成
  using P = function<T1(T1, int)>;
  P p;
  SegmentTree(const vector<T0>& a, F0 f0, T0 u0, F1 f1, T1 u1, G g, P p)
  : sz(a.size()), f0(f0), u0(u0), f1(f1), u1(u1), g(g), p(p) {
    for (N = 1; N < sz; N *= 2);
    node.resize(2 * N - 1);
    lazy.resize(2 * N - 1, u1);
    REP (i, sz) node[N - 1 + i] = a[i];
    for (int i = N - 2; i >= 0; i--) node[i] = f0(node[2 * i + 1], node[2 * i + 2]);
  }
  // [a, b)にxを作用
  void update(int a, int b, T1 x) {
    // assert(0 <= a && a < b && b <= sz);
    update(a, b, x, 0, 0, N);
  }
  void update(int a, T1 x) {
    update(a, a + 1, x);
  }
  // [a, b)
  T0 query(int a, int b) {
    return query(a, b, 0, 0, N);
  }
  T0 query(int a) {
    return query(a, a + 1);
  }
};

signed main() {
  int n, m; cin >> n >> m;
  vector<vector<ii>> ls(n);
  REP (i, m) {
    int l, r, a; cin >> l >> r >> a;
    l--; r--;
    ls[r].push_back({l, a});
  }
  // Max & Add
  SegmentTree<int, int> seg(
    vector<int>(n + 1, 0),
    [](int x, int y) { return max(x, y); }, 0,
    plus<int>(), 0,
    plus<int>(),
    [](int y, int len) { return y; }
  );

  REP (i, n) {
    int ma = seg.query(0, i + 1);
    seg.update(i + 1, ma);
    for (ii p: ls[i]) {
      seg.update(p.fi + 1, i + 1 + 1, p.se);
    }
  }
  cout << seg.query(0, n + 1) << endl;
}

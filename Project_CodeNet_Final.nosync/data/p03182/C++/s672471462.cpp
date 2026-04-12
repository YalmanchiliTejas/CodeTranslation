#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))
#define sz(v) ((int) v.size())

using namespace std;

using i64 = long long;
using f80 = long double;
using vi32 = vector<int>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

void yes() { cout << "Yes" << endl; exit(0); }
void no() { cout << "No" << endl; exit(0); }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> void amax(T &x, T y) { x = max(x, y); }
template <typename T> void amin(T &x, T y) { x = min(x, y); }
template <typename T> T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

const i64 INF = 1001001001001001001;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

template <typename T, typename S>
struct LazySegmentTree {
  vector<T> v;
  vector<S> z;
  function<T(T, T)> f;
  function<T(T, S, int)> g;
  function<S(S, S)> h;
  T e;
  S d;
  int n;
  LazySegmentTree(
    int size,
    function<T(T, T)> f,
    function<T(T, S, int)> g,
    function<S(S, S)> h,
    T e, 
    S d
  ) : f(f), g(g), h(h), e(e), d(d) {
    n = 1;
    while (n < size) n <<= 1;
    v.resize(n * 2, e);
    z.resize(n * 2, d);
  }
  void set(int k, T x) {
    v[k + n] = x;
  }
  void build() {
    for (int i = n - 1; i >= 0; i--) {
      v[i] = f(v[i * 2 + 0], v[i * 2 + 1]);
    }
  }
  void propagate(int k, int l, int r) {
    v[k] = g(v[k], z[k], r - l);
    if (k < n) {
      z[k * 2 + 0] = h(z[k * 2 + 0], z[k]);
      z[k * 2 + 1] = h(z[k * 2 + 1], z[k]);
    }
    z[k] = d;
  }
  T update(int a, int b, S x, int k = 1, int l = 0, int r = -1) {
    if (r == -1) r = n;
    propagate(k, l, r);
    if (b <= l || r <= a) return v[k];
    if (a <= l && r <= b) { z[k] = x; propagate(k, l, r); return v[k]; }
    return v[k] = f(
      update(a, b, x, k * 2 + 0, l, (l + r) / 2),
      update(a, b, x, k * 2 + 1, (l + r) / 2, r)
    );
  }
  T query(int a, int b, int k = 1, int l = 0, int r = -1) {
    if (r == -1) r = n;
    propagate(k, l, r);
    if (b <= l || r <= a) return e;
    if (a <= l && r <= b) return v[k];
    return f(
      query(a, b, k * 2 + 0, l, (l + r) / 2),
      query(a, b, k * 2 + 1, (l + r) / 2, r)
    );
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  using T = tuple<int, int, int, int>;
  vector<vector<T>> event(n + 1);
  rep(i, m) {
    int l, r, a;
    cin >> l >> r >> a;
    event[l].emplace_back(0, l, r, a);
    event[r].emplace_back(2, l, r, -a);
  }
  reps(i, n) {
    event[i].emplace_back(1, 0, 0, 0);
    sort(all(event[i]));
  }
  LazySegmentTree<i64, i64> lst(n + 1,
    [](i64 a, i64 b) { return max(a, b); },
    [](i64 a, i64 b, int k) { return a + b; },
    [](i64 a, i64 b) { return a + b; }, -INF, 0ll);
  i64 acc = 0;
  repc(i, n) {
    for (auto t : event[i]) {
      int kind, l, r, cost;
      tie(kind, l, r, cost) = t;
      if (kind == 0 || kind == 2) {
        lst.update(1, l, cost);
        acc += cost;
        continue;
      }
      lst.update(i, i + 1, INF + max(lst.query(1, i), acc));
    }
  }
  cout << max(0ll, lst.query(0, n + 1)) << endl;
}

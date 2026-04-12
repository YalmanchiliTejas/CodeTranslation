#pragma region header
#include <bits/stdc++.h>
#define int ll
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define mp make_pair
#define rep1(i, n) for (decltype(+n) i = 0; i < (n); i++)
#define rrep1(i, n) for (auto i = n - 1; i > static_cast<decltype(i)>(-1); i--)
#define rep2(i, a, b) for (auto i = (a); i < (b); i++)
#define rrep2(i, a, b) for (auto i = b - 1; i >= a; i--)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1) (__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep2, rrep1) (__VA_ARGS__)
#define each(i, a) for (auto &&i : (a))
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vd = vector<ld>;
using vvd = vector<vd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using mii = map<int, int>;
using vm = vector<mii>;
using vvm = vector<vm>;
template <class T, class U>
using umap = unordered_map<T, U>;
using umii = umap<int, int>;
using seti = set<int>;
template <class T>
using uset = unordered_set<T>;
using useti = uset<int>;
template <class T>
using less_queue = priority_queue<T>;
template <class T>
using greater_queue = priority_queue<T, vector<T>, greater<T>>;
using int128 = __int128_t;

ostream &operator<<(ostream &dest, int128 value) {
  ostream::sentry s(dest);
  if (s) {
    int128 tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(ios_base::badbit);
    }
  }
  return dest;
}

const int INF = 1e18;
const ld EPS = 1e-10;
template <class T>
void SORT(T &a) { stable_sort(all(a)); }
template <class T>
void RSORT(T &a) { stable_sort(rall(a)); }
template <class T>
void rev(T &a) { reverse(all(a)); }
template <class T>
void uniq(T &a) { a.erase(unique(all(a)), end(a)); }
template <class T>
auto min_of(const T &a) { return *min_element(all(a)); }
template <class T>
auto max_of(const T &a) { return *max_element(all(a)); }
template <class T>
T sum_of(const vector<T> &a) { return accumulate(all(a), (T)0); }
template <class T, class U>
int count_of(const T &a, const U &i) { return count(all(a), i); }
template <class T>
bool has(const vector<T> &a, const T &i) { return find(all(a), i) != a.end(); }
bool has(const string &a, const char &i) { return find(all(a), i) != a.end(); }
template <class T>
bool has(const set<T> &a, const T &i) { return a.find(i) != a.end(); }
template <class T, class U>
bool has(const map<T, U> &a, const T &i) { return a.find(i) != a.end(); }
template <class T, class U>
bool has(const umap<T, U> &a, const T &i) { return a.find(i) != a.end(); }
template <class T>
int sz(const T &a) { return a.size(); };

void CIN() {};
template <class T, class... U>
void CIN(T &&x, U &&...y) {
  cin >> x;
  CIN(forward<U>(y)...);
}
void _COUT() { cout << '\n'; }
template <class T, class... U>
void _COUT(T &&x, U &&...y) {
  cout << ' ' << x;
  _COUT(forward<U>(y)...);
}
void COUT() { _COUT(); };
template <class T, class... U>
void COUT(T &&x, U &&...y) {
  cout << x;
  _COUT(forward<U>(y)...);
}
template <class T>
void CSP(const T &x) { cout << x << ' '; }
template <class T>
void CVEC(const T &v) {
  int c = v.size() - 1;
  for (int i = 0; i < c; i++) cout << v[i] << ' ';
  if (c > -1) cout << v[c];
  cout << '\n';
}

template <class T>
bool amin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool amax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

constexpr int lshift(const int &x) noexcept { return 1ll << x; }
constexpr int popcount(const int &x) noexcept { return __builtin_popcountll(x); }
constexpr int least1(const int &x) noexcept { return __builtin_ffsll(x); }
constexpr int ceil_div(const int &x, const int &y) noexcept { return (x + y - 1) / y; }

#pragma endregion header

template <typename T>
struct segment_tree {
  using F = function<T(T, T)>;
  using C = function<bool(T)>;
  int sz;
  vector<T> seg;

  const F f;
  const T M1;

  segment_tree(int n, const F f, const T &M1) : f(f), M1(M1) {
    sz = 1;
    while (sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
  segment_tree(const vector<T> &v, const F f, const T &M1) : f(f), M1(M1) {
    int n = int(v.size());
    sz = 1;
    while (sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
    for (int i = 0; i < n; i++) set(i, v[i]);
    build();
  }

  void set(int k, const T &x) { seg[k + sz] = x; }

  void build() { for (int k = sz - 1; k > 0; k--) seg[k] = f(seg[2 * k], seg[2 * k + 1]); }

  void update(int k, const T &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1) seg[k] = f(seg[2 * k], seg[2 * k + 1]);
  }

  T query(int a, int b) {
    T L = M1, R = M1;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = f(L, seg[a++]);
      if (b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  T operator[](const int &k) const { return seg[k + sz]; }

  int find_subtree(int a, const C &check, T &M, bool type) {
    while (a < sz) {
      T nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if (check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  int find_first(int a, const C &check) {
    T L = M1;
    if (a <= 0) {
      if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) {
        T nxt = f(L, seg[a]);
        if (check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  int find_last(int b, const C &check) {
    T R = M1;
    if (b >= sz) {
      if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for (b += sz; a < b; a >>= 1, b >>= 1) {
      if (b & 1) {
        T nxt = f(seg[--b], R);
        if (check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

#pragma region main
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, Q;
  CIN(N, Q);
  vi A(N);
  each(x, A) CIN(x);
  segment_tree<int> st(A, [](int a, int b) { return max(a, b); }, -1);

  rep(_, Q) {
    int t, l, r;
    CIN(t, l, r);
    l--;
    if (t == 1) st.update(l, r);
    else if (t == 2) COUT(st.query(l, r));
    else {
      int j = st.find_first(l, [&](int x) { return x >= r; });
      COUT(j == -1 ? N + 1 : j + 1);
    }
  }
}
#pragma endregion main

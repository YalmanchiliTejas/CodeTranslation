#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct LazySeg {
  using T = ll;
  static T op(const T& a, const T& b) { return max(a, b); }
  static constexpr T e() { return -1e14; }
  using U = ll;
  static void ap(const U& f, T& a) { a += f; }
  static void cp(const U& g, U& f) { f += g; }
  static constexpr U id() { return 0LL; }
 
  const int n;
  vector<T> t;
  vector<U> u;
  LazySeg(int _n) : n(_n), t(2 * n, e()), u(n, id()) {}
  T& operator[](int i) { return t[i + n]; }
  void build() { for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
  void push() { for (int i = 1; i < n; ++i) push(i); }
  void apply(const U& f, int i) {
    ap(f, t[i]);
    if (i < n) cp(f, u[i]);
  }
  void push(int i) {
    if (u[i] == id()) return;
    apply(u[i], 2 * i);
    apply(u[i], 2 * i + 1);
    u[i] = id();
  }
  void push(int l, int r) {
    for (int hl = __lg(l + n), hr = __lg(r - 1 + n); hr > 0; --hl, --hr) {
      int al = (l + n) >> hl, ar = (r - 1 + n) >> hr;
      if (al < n) push(al);
      if (ar != al) push(ar);
    }
  }
  T query(int l, int r) {
    r++;
    push(l, r);
    T resl = e(), resr = e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, t[l++]);
      if (r & 1) resr = op(t[--r], resr);
    }
    return op(resl, resr);
  }
  T get(int i) { return query(i, i); }
  void update(int l, int r, const U& f) {
    r++;
    push(l, r);
    for (int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
      if (i & 1) apply(f, i++);
      if (j & 1) apply(f, --j);
    }
    l = (l + n) >> __builtin_ctz(l + n);
    while (l >>= 1) t[l] = op(t[2 * l], t[2 * l + 1]);
    r = (r + n) >> __builtin_ctz(r + n);
    while (r >>= 1) t[r] = op(t[2 * r], t[2 * r + 1]);
  }
  void set(int i, const T& a) {
    push(i, i + 1);
    t[i += n] = a;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};

constexpr int MAXN = 200005;

int n, m;
vector<pair<int, ll>> byStart[MAXN];
vector<pair<int, ll>> byEnd[MAXN];
LazySeg st(MAXN);

void print() {
  for (int i = 0; i < n; i++) {
    cout << st.get(i) << " ";
  }
  cout << "\n";
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r; ll a; cin >> l >> r >> a;
    byStart[l].emplace_back(r, a);
    byEnd[r].emplace_back(l, a);
  }

  for (int i = 0; i <= n; i++) {
    st.set(i, 0);
  }
  st.build();
  
  // take nothing
  ll res = 0;

  for (int i = 1; i <= n; i++) {
    // activate every interval that starts at i
    for (auto& pr : byStart[i]) {
      ll a = pr.second;
      st.update(0, i - 1, a);
    }

    // represents maximum score of prefix of length i if s[i] == '1'
    ll cur = st.query(0, i - 1);
    res = max(res, cur);
    st.update(i, i, cur);

    // deactivate every interval that ends at i
    for (auto& pr : byEnd[i]) {
      int l = pr.first;
      ll a = pr.second;
      st.update(0, l - 1, -a);
    }
  }
  cout << res << "\n";
  return 0;
}

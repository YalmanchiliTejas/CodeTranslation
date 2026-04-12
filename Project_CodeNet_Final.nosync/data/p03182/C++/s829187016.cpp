#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
/* clang-format on */

template <typename Val, typename Laziness>
struct LazyPropagationSegmentTreeBase {
  vector<Val> nodes;
  vector<Laziness> laziness;
  vector<bool> islazy;
  int n;
  void init(int n_, const Val &v = Val()) {
    init(vector<Val>(n_, v));
  }
  void init(const vector<Val> &u) {
    n = 1;
    while (n < (int)u.size()) n *= 2;
    nodes.resize(n);
    nodes.insert(nodes.end(), u.begin(), u.end());
    nodes.resize(n * 2, Val());
    for (int i = n - 1; i > 0; --i)
      nodes[i] = nodes[i * 2] + nodes[i * 2 + 1];
    laziness.assign(n, Laziness());
    islazy.assign(n, false);
  }
  Val get(int i) {
    static int indices[128];
    int k = getIndices(indices, i, i + 1);
    propagateRange(indices, k);
    return nodes[i + n];
  }
  Val getRange(int i, int j) {
    static int indices[128];
    int k = getIndices(indices, i, j);
    propagateRange(indices, k);
    Val res = Val();
    for (int l = i + n, r = j + n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += value(l++);
      if (r & 1) res += value(--r);
    }
    return res;
  }
  void set(int i, const Val &x) {
    static int indices[128];
    int k = getIndices(indices, i, i + 1);
    propagateRange(indices, k);
    nodes[n + i] = x;
    mergeRange(indices, k);
  }
  void addToRange(int i, int j, const Laziness &x) {
    if (i >= j) return;
    static int indices[128];
    int k = getIndices(indices, i, j);
    propagateRange(indices, k);
    int l = i + n, r = j + n;
    if (l & 1) nodes[l++] += x;
    if (r & 1) nodes[--r] += x;
    for (l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) islazy[l] = true, laziness[l++] += x;
      if (r & 1) laziness[--r] += x, islazy[r] = true;
    }
    mergeRange(indices, k);
  }

 private:
  int getIndices(int indices[128], int i, int j) {
    int k = 0, l, r;
    if (i >= j) return 0;
    for (l = (n + i) >> 1, r = (n + j - 1) >> 1; l != r; l >>= 1, r >>= 1) {
      indices[k++] = l;
      indices[k++] = r;
    }
    for (; l; l >>= 1) indices[k++] = l;
    return k;
  }
  void propagateRange(int indices[], int k) {
    for (int i = k - 1; i >= 0; --i)
      propagate(indices[i]);
  }
  void mergeRange(int indices[], int k) {
    for (int i = 0; i < k; ++i)
      merge(indices[i]);
  }
  inline void propagate(int i) {
    if (i >= n || !islazy[i]) return;
    nodes[i] += laziness[i] * width(i);
    if (i * 2 < n) {
      laziness[i * 2] += laziness[i];
      laziness[i * 2 + 1] += laziness[i];
      islazy[i * 2] = true;
      islazy[i * 2 + 1] = true;
    } else {
      nodes[i * 2] += laziness[i];
      nodes[i * 2 + 1] += laziness[i];
    }
    laziness[i] = Laziness();
    islazy[i] = false;
  }
  inline void merge(int i) {
    if (i >= n) return;
    nodes[i] = value(i * 2) + value(i * 2 + 1);
  }
  inline Val value(int i) {
    propagate(i);
    return nodes[i];
  }
  inline int width(int i) {
    i |= i >> 1;
    i |= i >> 2;
    i |= i >> 4;
    i |= i >> 8;
    i |= i >> 16;
    return n / ((i + 1) >> 1);
  }
};

template <typename Val>
struct AddVal {
  Val x;
  AddVal()
      : x(Val()) {
  }
  AddVal(Val x_)
      : x(x_) {
  }
  operator Val() {
    return x;
  }
  AddVal &operator+=(AddVal that) {
    x += that.x;
    return *this;
  }
  AddVal operator*(int w) {
    return *this;
  }
};
template <typename Val>
struct MaxVal {
  Val x;
  MaxVal()
      : x(std::numeric_limits<Val>::min()) {
  }
  MaxVal(Val x_)
      : x(x_) {
  }
  operator Val() {
    return x;
  }
  MaxVal operator+(MaxVal that) const {
    return max(x, that.x);
  }
  MaxVal &operator+=(MaxVal that) {
    return *this = *this + that;
  }
  MaxVal &operator+=(AddVal<Val> y) {
    x += y;
    return *this;
  }
};

template <typename Val>
struct StarrySkyTree : LazyPropagationSegmentTreeBase<MaxVal<Val>, AddVal<Val>> {};

int main() {
  int N, M;
  while (cin >> N >> M) {
    vector<int> l(M), r(M);
    vector<ll> a(M);
    for (int i = 0; i < M; i++) cin >> l[i] >> r[i] >> a[i], --l[i], --r[i];
    vec<int, 2> R(N);
    for (int i = 0; i < M; i++) R[r[i]].push_back(i);
    StarrySkyTree<ll> st;
    st.init(N);
    for (int x = 0; x < N; x++) {
      ll y = 0;
      if (x > 0) {
        y = max(0ll, st.getRange(0, x).x);
      }
      st.set(x, y);
      for (int i : R[x]) {
        st.addToRange(l[i], r[i] + 1, a[i]);
      }
    }
    ll res = max(0ll, st.getRange(0, N).x);
    cout << res << endl;
  }
  return 0;
}

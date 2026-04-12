#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;

#pragma region template

#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

// Useful utilities.
namespace Util {

// sprintf that returns a string.
string ssprintf(const string fmt_str, ...) {
  int final_n, n = ((int)fmt_str.size()) * 2;
  unique_ptr<char[]> formatted;
  va_list ap;
  while (1) {
    formatted.reset(new char[n]);
    strcpy(&formatted[0], fmt_str.c_str());
    va_start(ap, fmt_str);
    final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
    va_end(ap);
    if (final_n < 0 || final_n >= n)
      n += abs(final_n - n + 1);
    else
      break;
  }
  return string(formatted.get());
}

template <class T> void assign(T &a, T b) { a = b; }
template <class T, class U> void assign(T &a, U &b, T c, U d) { a = c, b = d; }
template <class T, class U, class V> void assign(T &a, U &b, V &c, T d, U e, V f) { a = d, b = e, c = f; }
template <class T, class U, class V, class W> void assign(T &a, U &b, V &c, W &d, T e, U f, V g, W h) {
  a = e, b = f, c = g, d = h;
}

} // namespace Util

namespace Math {

ll modpow(ll b, ll p, ll m) {
  ll r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      r = r * b % m;
  return r;
}

ll modinv(ll b, ll m) { return modpow(b, m - 2, m); }

ll sumdigit(ll num) {
  ll res = 0;
  while (num) {
    res += num % 10;
    num /= 10;
  }
  return res;
}

ll sumdigit(string num) {
  ll res = 0;
  for (char c : num)
    res += c - '0';
  return res;
}

template <class T> T gcd(T a, T b) { return abs(__gcd(a, b)); }
template <class T> T clamp(T n, T l, T r) { return n < l ? l : n > r ? r : n; }
template <class T> T lcm(T a, T b) { return abs(a / gcd(a, b) * b); }
template <class T> T sgn(T n) { return n == 0 ? 0 : n > 0 ? 1 : -1; }

struct Log2Table {
  vector<int> val;
  // Last value that we computed to.
  int pmax = 0;

  Log2Table() {
    val.resize(1);
    val[0] = -1;
  }

  int get(int n) {
    if (n >= val.size()) {
      eprintf("Error: request log2[%d] but is not computed yet\n", n);
      exit(1);
    }

    return val[n];
  }

  void require(int n) {
    if (n < pmax)
      return;
    val.resize(n + 1);

    for (int i = 0; i < 30; i++)
      for (int j = max(1 << i, pmax + 1); j < min(1 << (i + 1), n + 1); j++)
        val[j] = i;

    pmax = n;
  }
};

Log2Table log2t;

// Generic modular integer.
template <int MOD, typename IntType = int> struct GModint {
  IntType val;

  GModint() : val(0) {}
  GModint(int v, bool safe = false) { val = safe ? v : ((v % MOD) + MOD) % MOD; }
  GModint(ll v, bool safe = false) { val = safe ? v : ((v % MOD) + MOD) % MOD; }

  explicit operator bool() const { return val != 0; }
  const bool operator==(const GModint &g) const { return val == g.val; }
  const bool operator!=(const GModint &g) const { return val != g.val; }
  const GModint operator+=(const GModint &g) { return *this = *this + g; }
  const GModint operator-=(const GModint &g) { return *this = *this - g; }
  const GModint operator*=(const GModint &g) { return *this = *this * g; }
  const GModint operator/=(const GModint &g) { return *this = *this / g; }
  const GModint operator^=(const GModint &g) { return *this = *this ^ g; }
  const GModint operator-() const { return GModint(val == 0 ? 0 : MOD - val, true); }
  const GModint operator+(const GModint &g) const {
    ll newval = val + g.val;
    if (newval >= MOD)
      newval -= MOD;
    return GModint(newval, true);
  }
  const GModint operator-(const GModint &g) const { return *this + (-g); }
  const GModint operator*(const GModint &g) const { return GModint(1ll * val * g.val); }
  const GModint operator/(const GModint &g) const { return *this * g.inv(); }
  template <class T> const GModint operator^(const T t) const { return GModint(modpow(val, t, MOD)); }
  const GModint inv() const { return GModint(modinv(val, MOD)); }
};

using Modint = GModint<1000000007>;

} // namespace Math

namespace DS {

// Building a 0-based sparse table for associative operations.
// i.e. A op (B op C) = (A op B) op C
template <class T, class Combiner> struct SparseTable {
  int n, nlog, base;
  vector<vector<T>> st;
  Combiner combiner;

  SparseTable(int n, T *t, int base = 0) : n(n), base(base) {
    Math::log2t.require(n);

    nlog = Math::log2t.get(n);

    st.resize(nlog + 1);
    for (int i = 0; i <= nlog; i++)
      st[i].resize(n + base);

    for (int j = 0; j < n + base; j++)
      st[0][j] = t[j];
    for (int i = 1; i <= nlog; i++)
      for (int j = 0; j + (1 << (i - 1)) < n; j++)
        st[i][j] = combiner(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }

  T query(int l, int r) {
    if (l > r) {
      eprintf("Error: sparse table query (L, R) = (%d, %d).\n", l, r);
      exit(1);
    }

    l = Math::clamp(l, 0, n - 1);
    r = Math::clamp(r, 0, n - 1);

    int len = Math::log2t.get(r - l + 1);
    T val = st[len][l];
    l += 1 << len;

    if (l <= r)
      val = combiner(val, query(l, r));

    return val;
  }
};

template <class T> struct SparseTableCombinerSample {
  const T operator()(const T &a, const T &b) { return a + b; }
};

struct DSU {
  int size;
  vector<int> dsu, block;

  DSU() {}
  DSU(int size) { init(size); }

  void init(int new_size) {
    size = new_size;
    dsu.resize(size + 1);
    block.resize(size + 1);
    for (int i = 0; i <= size; i++)
      dsu[i] = i, block[i] = 1;
  }

  int find(int u) { return u == dsu[u] ? u : dsu[u] = find(dsu[u]); }
  bool same_component(int u, int v) { return find(u) == find(v); }
  void merge(int u, int v) {
    if (!same_component(u, v)) {
      block[find(u)] += block[find(v)];
      dsu[find(v)] = find(u);
    }
  }
  int block_size(int u) { return block[find(u)]; }
};

} // namespace DS

namespace Graph {

const int NODE_NIL = -1;

template <typename LenType> struct Edge {
  int from, to;
  LenType len;

  Edge(int from, int to, LenType len) : from(from), to(to), len(len) {}
};

template <typename LenType> struct Graph {
  using edge = Edge<LenType>;

  vector<vector<edge>> G;
  int n;

  Graph() {}
  Graph(int size) { resize(size); }

  void resize(int new_size) {
    n = new_size;
    G.resize(n + 1);
  }

  void add_edge(int from, int to, LenType len = 1) { G[from].push_back(edge(from, to, len)); }
  void add_bidir_edge(int u, int v, LenType len = 1) { add_edge(u, v, len), add_edge(v, u, len); }
};

template <typename LenType> struct Tree : public Graph<LenType> {
  using edge = typename Graph<LenType>::edge;
  using Graph<LenType>::n;
  using Graph<LenType>::G;

  int root;
  vector<LenType> depth, parent;

  Tree() : Graph<LenType>() {}
  Tree(int size) : Graph<LenType>(size) {}

  void init_dfs(int n, int p = NODE_NIL) {
    typename vector<edge>::iterator it_parent = G[n].end();
    parent[n] = p;

    for (typename vector<edge>::iterator it = G[n].begin(); it != G[n].end(); it++) {
      if (it->to == p) {
        it_parent = it;
      } else {
        depth[it->to] = depth[n] + it->len;
        init_dfs(it->to, n);
      }
    }

    if (it_parent != G[n].end()) {
      G[n].erase(it_parent);
    }
  }

  void init_tree(int new_root = 1, int root_depth = 0) {
    root = new_root;

    depth.resize(n + 1);
    parent.resize(n + 1);

    depth[root] = root_depth;

    init_dfs(root);
  }
};

using UnweightedTree = Tree<int>;

struct LCA {
  int n, nlog;
  vector<int> depth;
  vector<vector<int>> jump_table;

  LCA(const UnweightedTree &tree) { init(tree); }
  void init(const UnweightedTree &tree) {
    n = tree.n;
    depth = tree.depth;

    Math::log2t.require(n);
    nlog = Math::log2t.get(n);

    jump_table.resize(nlog + 1);
    for (int i = 0; i <= nlog; i++)
      jump_table[i].resize(n + 1);
    for (int i = 0; i <= n; i++)
      jump_table[0][i] = tree.parent[i];
    for (int i = 1; i <= nlog; i++)
      for (int j = 0; j <= n; j++)
        jump_table[i][j] = jump_table[i - 1][j] == NODE_NIL ? NODE_NIL : jump_table[i - 1][jump_table[i - 1][j]];
  }

  int up(int node_id, int level) {
    for (int i = nlog; i >= 0; i--)
      if ((level >> i) & 1)
        node_id = jump_table[i][node_id];
    return node_id;
  }

  int lca(int u, int v) {
    if (depth[u] > depth[v])
      swap(u, v);
    v = up(v, depth[v] - depth[u]);
    if (u == v)
      return u;
    for (int i = nlog; i >= 0; i--)
      if (jump_table[i][u] != jump_table[i][v])
        u = jump_table[i][u], v = jump_table[i][v];
    return jump_table[0][u];
  }

  int dist(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
  }

  int furthest_node(int node, int node_lo, int node_hi) {
    int furthest = node, furthest_dist = 0;
    for (int i = node_lo; i <= node_hi; i++)
      if (i != node) {
        int new_dist = dist(node, i);
        if (new_dist > furthest_dist)
          furthest = i, furthest_dist = new_dist;
      }
    return furthest;
  }

  int diameter(int node_lo, int node_hi) {
    int node1 = furthest_node(node_lo, node_lo, node_hi);
    int node2 = furthest_node(node1, node_lo, node_hi);
    return dist(node1, node2);
  }
};

} // namespace Graph

namespace Regex {

bool match(string regex_rule, string content) {
  regex r(regex_rule);
  return regex_match(content, r);
}

} // namespace Regex

template <int MOD> ostream &operator<<(ostream &out, const Math::GModint<MOD> m) {
  out << m.val;
  return out;
}

template <class T> ostream &operator<<(ostream &out, const vector<T> v) {
  out << "[";
  for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
    out << *it;
    if (next(it) != v.end())
      out << ", ";
  }
  out << "]";
  return out;
}

template <class T, class U> ostream &operator<<(ostream &out, const map<T, U> m) {
  out << "{";
  for (typename map<T, U>::const_iterator it = m.begin(); it != m.end(); it++) {
    out << it->first << " -> " << it->second;
    if (next(it) != m.end())
      out << ", ";
  }
  out << "}";
}

template <class T> ostream &operator<<(ostream &out, const set<T> s) {
  out << "(";
  for (typename set<T>::iterator it = s.begin(); it != s.end(); it++) {
    out << *it;
    if (next(it) != s.end())
      out << ", ";
  }
  out << ")";
}

template <class T, class U> ostream &operator<<(ostream &out, const pair<T, U> p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

#pragma endregion template

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int x, y, z;
  cin >> x >> y >> z;

  for (int i = 1;; i++) {
    int len = z * (i + 1) + y * i;
    if (len > x) {
      cout << i - 1 << endl;
      return 0;
    }
  }
}
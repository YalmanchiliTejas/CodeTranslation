#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int kMaxN = 2e5 + 7;
constexpr ll inf = 1e18;

vector<pair<int, bool>> in[kMaxN];
vector<pair<int, bool>> out[kMaxN];

struct SegTree {
  struct node {
    ll big = -inf;
    ll lazy = 0;
  };
  int sz, n;
  vector<node> nodes;

  SegTree(int n): n{n} {
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    nodes.resize(2 * sz);
  }

  ll get_max() {
    ll v = -inf;
    rec(1, 0, sz - 1, 0, sz - 1, v, false);
    return v;
  }

  void add(int l, int r, ll val) {
    rec(1, 0, sz - 1, l, r, val, true);
  }

private:

  void prop(int idx) {
    if (!nodes[idx].lazy) {
      return;
    }

    int l = 2 * idx, r = l + 1;
    if (r < 2 * sz) {
      nodes[l].lazy += nodes[idx].lazy;
      nodes[r].lazy += nodes[idx].lazy;
    }

    nodes[idx].big += nodes[idx].lazy; 
    nodes[idx].lazy = 0;
  }

  void rec(int idx, int L, int R, int l, int r, ll& val, bool add) {
    prop(idx);
    if (l > R || r < L) {
      return;
    }
    if (l <= L && R <= r) {
      if (add) {
        nodes[idx].lazy += val;
        prop(idx);
      } else {
        val = max(val, nodes[idx].big);
      }
      return;
    }
    int M = (L + R) / 2;
    rec(2 * idx, L, M, l, r, val, add);
    rec(2 * idx + 1, M + 1, R, l, r, val, add);
    nodes[idx].big = max(nodes[2 * idx].big, nodes[2 * idx + 1].big);
  }
};

struct inter {
  int l, r;
  ll a;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector<inter> original(m);
  for (int i = 0; i < m; ++i) {
    int l, r;
    ll a;
    cin >> l >> r >> a;

    original[i] = {l, r, a};
    in[l].emplace_back(i, true);
    out[r].emplace_back(i, false);
  }

  SegTree st(n + 2);

  st.add(0, 0, inf);
  for (int i = 1; i <= n; ++i) {
    for (auto& p: in[i]) {
      auto &interval = original[p.first];
      st.add(0, interval.l - 1, interval.a);
    }

    st.add(i, i, st.get_max() + inf);

    for (auto& p: out[i]) {
      auto &interval = original[p.first];
      st.add(0, interval.l - 1, -interval.a);
    }
  }

  cout << st.get_max() << '\n';

  return 0;
}

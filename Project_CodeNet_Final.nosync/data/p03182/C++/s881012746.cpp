#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> m >> n;

  vector<vector<pair<int, int>>> seg(m + 1);
  i64 s = 0;
  for (int i = 0; i < n; ++i) {
    int l, r, w;
    cin >> l >> r >> w;
    seg[r].emplace_back(l, w);
    s += w;
  }
  struct node {
    i64 min{};
    i64 add{};

    node() = default;
    node(i64 min, i64 add) : min(min), add(add) {}
  };
  vector<node> tree(4 * (m + 1));
  auto join = [](node const& x, node const& y) {
    assert(!x.add);
    assert(!y.add);
    return node(min(x.min, y.min), 0);
  };
  auto pull = [&](int v) {
    tree[v] = join(tree[2 * v], tree[2 * v + 1]);
  };
  auto push = [&](int v, int l, int r) {
    tree[v].min += tree[v].add;
    if (l != r) {
      tree[2 * v].add += tree[v].add;
      tree[2 * v + 1].add += tree[v].add;
    }
    tree[v].add = 0;
  };
  function<void(int, int, int, int, int, i64)> add_seg =
          [&](int v, int l, int r, int ql, int qr, i64 delta) {
    push(v, l, r);
    if (l > qr || ql > r) {
      return;
    }
    if (ql <= l && r <= qr) {
      tree[v].add += delta;
      push(v, l, r);
      return;
    }
    auto m = (l + r) / 2;
    add_seg(2 * v, l, m, ql, qr, delta);
    add_seg(2 * v + 1, m + 1, r, ql, qr, delta);
    pull(v);
  };
  function<node(int, int, int, int, int)> query =
          [&](int v, int l, int r, int ql, int qr) {
    push(v, l, r);
    if (l > qr || ql > r) {
      return node(numeric_limits<i64>::max() / 4, 0);
    }
    if (ql <= l && r <= qr) {
      return tree[v];
    }
    auto m = (l + r) / 2;
    return join(query(2 * v, l, m, ql, qr),
            query(2 * v + 1, m + 1, r, ql, qr));
  };
  for (int r = 1; r <= m + 1; ++r) {
    for (auto const& sg : seg[r - 1]) {
      add_seg(1, 0, m, 0, sg.first - 1, sg.second);
    }
    auto result = query(1, 0, m, 0, r - 1).min;
    if (r == m + 1) {
      cout << s - result << '\n';
      return 0;
    }
    add_seg(1, 0, m, r, r, result);
  }
  return 0;
}
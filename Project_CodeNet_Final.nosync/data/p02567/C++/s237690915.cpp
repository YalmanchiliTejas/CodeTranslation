#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template <bool P = 0> struct SegmentTree {
  #define lson L, R, N[u].l
  #define rson L, R, N[u].r
  #define OUT R <= N[u].L || N[u].R <= L
  #define IN  L <= N[u].L && N[u].R <= R
  struct Node { int L, R, l, r;
    LL maxV, idx;
  };
  vector<Node> N; int p, n; vector<int> rt;
  inline void init(int _n) { N.resize(_n * (P ? 40:4));
    n = _n; p = 1; rt.assign(1, build(0, n));
  }
  inline int copy(Node u) { return N[p] = u, p++; }
  int build(int L, int R) {
    int u = copy({L, R}), M = (L + R) >> 1;;
    if (R - L == 1) return N[u].idx = L, u;
    return pull(u, build(L, M), build(M, R));
  }
  inline int push(int u) {
    return u;
  }
  inline int pull(int u, int l, int r) {
    if (!l || !r) return l ? l : r;
    N[u].L = N[l].L; N[u].R = N[r].R;
    push(N[u].l = l); push(N[u].r = r);
    if (N[l].maxV >= N[r].maxV)
      N[u].idx = N[l].idx;
    else
      N[u].idx = N[r].idx;
    N[u].maxV = max(N[l].maxV, N[r].maxV);
    return u;
  }
  int m(int L, int R, int u, LL v) {
    if (OUT) return u; push(u);
    if (P) u = copy(N[u]);
    if (IN) return N[u].maxV = v, u;
    return pull(u, m(lson, v), m(rson, v));
  }
  int q(int L, int R, int u) {
    if (OUT) return 0; push(u); if (IN) return u;
    return pull(copy(N[u]), q(lson), q(rson));
  }
  inline void modify(int L, int R, int ver, LL v) {
    rt[ver] = m(L, R, rt[ver], v);
  }
  inline Node& query(int L, int R, int ver) {
    if (!P) p = 2 * n; return N[q(L, R, rt[ver])];
  }
  inline int lb(int x, LL v, int ver) {
    if (!P) p = 2 * n; return lb_q(x, v, rt[ver]);
  }
  int lb_q(int x, LL v, int u) {
    if (N[u].R - N[u].L == 1)
      return (N[u].maxV >= v) ? u : 0;
    if (N[N[u].l].R > x) {
      int left = lb_q(x, v, N[u].l);
      if (left && N[left].maxV >= v)
        return left;
    }
    return lb_q(x, v, N[u].r);
  }
};
SegmentTree solver;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    solver.init(n);
    for (int i = 0 ; i < n ; i++) {
        LL v; cin >> v;
        solver.modify(i, i + 1, 0, v);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; LL v; cin >> x >> v; x--;
            solver.modify(x, x + 1, 0, v);
        } else if (t == 2) {
            int l, r; cin >> l >> r; l--;
            cout << solver.query(l, r, 0).maxV << '\n';
        } else {
            int x; LL v; cin >> x >> v; x--;
            int res = solver.lb(x, v, 0);
            if (res == 0) {
                cout << n + 1 << '\n';
            } else {
                cout << solver.N[res].idx + 1 << '\n';
            }
        }
    }
}
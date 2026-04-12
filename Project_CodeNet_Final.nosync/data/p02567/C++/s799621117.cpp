#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include <atcoder/segtree>

int max_op(int x, int y) { return std::max(x, y); }
int max_e() { return -1e9; }

int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  std::vector<int> a(n);
  for (auto& ai: a) scanf("%d", &ai);

  atcoder::segtree<int, max_op, max_e> max_st(a);

  for (int i = 0; i < q; ++i) {
    int t;
    scanf("%d", &t);

    if (t == 1) {
      int x, v;
      scanf("%d %d", &x, &v);
      --x;
      max_st.set(x, v);
    } else if (t == 2) {
      int l, r;
      scanf("%d %d", &l, &r);
      --l;
      printf("%d\n", max_st.prod(l, r));
    } else if (t == 3) {
      int x, v;
      scanf("%d %d", &x, &v);
      --x;
      printf("%d\n", max_st.max_right(x, [&](int prod) { return v > prod; }) + 1);
    }
  }
}

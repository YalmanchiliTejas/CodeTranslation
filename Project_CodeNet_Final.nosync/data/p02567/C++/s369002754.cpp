#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int e()
{
  return -1;
}

int op(int a, int b)
{
  return max(a, b);
}

int main()
{
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }

  segtree<int, op, e> seg(a);

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, v;
      cin >> x >> v;
      x--;
      seg.set(x, v);
    } else if (t == 2) {
      int l, r;
      cin >> l >> r;
      l--;
      cout << seg.prod(l, r) << endl;
    } else {
      int x, v;
      cin >> x >> v;
      x--;
      cout << seg.max_right(x, [&](auto a){return a < v;}) + 1 << endl;
    }
  }
}

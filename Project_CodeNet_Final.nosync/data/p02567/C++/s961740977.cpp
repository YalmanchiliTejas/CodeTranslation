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

  segtree<int, op, e> seg(n);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    seg.set(i, x);
  }

  for (int i = 0; i < q; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    a--;
    switch (t) {
    case 1: seg.set(a, b); break;
    case 2: cout << seg.prod(a, b) << endl; break;
    case 3: cout << seg.max_right(a, [&](auto x){return x < b;}) + 1 << endl; break;
    }
  }
}

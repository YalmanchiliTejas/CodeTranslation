#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int target;

bool f(int v) { return v < target; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  segtree<int, op, e> seg(a);
  while (q--) {
    int ti;
    cin >> ti;
    if (ti == 1) {
      int xi, vi;
      cin >> xi >> vi;
      xi--;
      seg.set(xi, vi);
    } else if (ti == 2) {
      int li, ri;
      cin >> li >> ri;
      li--;
      cout << seg.prod(li, ri) << '\n';
    } else {
      int xi;
      cin >> xi >> target;
      xi--;
      cout << seg.max_right<f>(xi) + 1 << '\n';
    }
  }
  return 0;
}
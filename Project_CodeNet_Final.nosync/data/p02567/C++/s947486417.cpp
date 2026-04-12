#include <bits/stdc++.h>
#include <atcoder/segtree>

using namespace std;
using namespace atcoder;

int xx;

int merge(int a, int b) {
  return max(a, b);
}

int single() {
  return INT_MIN;
}

bool check(int x) {
  return x < xx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& foo : a) {
    cin >> foo;
  }
  segtree<int, merge, single> st(a);
  while (q--) {
    int op, x;
    cin >> op >> x >> xx;
    if (op == 1) {
      st.set(x - 1, xx);
    } else if (op == 2) {
      cout << st.prod(x - 1, xx) << '\n';
    } else {
      cout << st.max_right<check>(x - 1) + 1 << '\n';
    }
  }
  return 0;
}
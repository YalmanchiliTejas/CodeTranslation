#include <atcoder/segtree>
#include <iostream>
#include <vector>
#define rep(i, j, n) for (int i = j; i < n; ++i)
using namespace std;

int b;
bool f(int a) { return a < b; }

int main() {
  int n, q, t, x, v;
  cin >> n >> q;
  vector<int> a(n);
  for (int& z : a) cin >> z;
  auto op = [](int a, int b) { return std::max(a, b); };
  auto e = []() { return 0; };
  atcoder::segtree<int, op, e> st(a);

  rep(i, 0, q) {
    cin >> t >> x >> v;
    --x;
    if (t == 1)
      st.set(x, v);
    else if (t == 2)
      cout << st.prod(x, v) << '\n';
    else {
      b = v;
      cout << st.max_right<f>(x) + 1 << '\n';
    }
  }

  return 0;
}
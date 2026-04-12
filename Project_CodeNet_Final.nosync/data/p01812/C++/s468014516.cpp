#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  V<> D(m); for (auto&& e : D) cin >> e, --e;
  sort(begin(D), end(D));
  VV<> to(n, V<>(k)); for (auto&& v : to) for (auto&& e : v) cin >> e, --e;
  V<> d(1 << m, -1);
  queue<int> que;
  d.back() = 0;
  que.push(~(~0 << m));
  while (!que.empty()) {
    int bit = que.front(); que.pop();
    if (!bit) return cout << d[bit] << '\n', 0;
    for (int j = 0; j < k; ++j) {
      int nbit = 0;
      for (int i = 0; i < m; ++i) if (bit >> i & 1) {
        if (!binary_search(begin(D), end(D), to[D[i]][j])) continue;
        nbit |= 1 << lower_bound(begin(D), end(D), to[D[i]][j]) - begin(D);
      }
      if (d[nbit] == -1) {
        d[nbit] = d[bit] + 1;
        que.push(nbit);
      }
    }
  }
}

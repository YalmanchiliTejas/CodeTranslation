#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> h(n); for (auto&& e : h) cin >> e;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    bool f = true;
    for (int j = 0; j < i; ++j) if (h[j] > h[i]) {
      f = false;
      break;
    }
    res += f;
  }
  cout << res << '\n';
}
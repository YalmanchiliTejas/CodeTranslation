#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, l, r;
  while (cin >> n >> l >> r, n) {
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    int res = 0;
    for (int x = l; x <= r; ++x) {
      int mi = n;
      for (int i = 0; i < n; ++i) {
        if (x % a[i] == 0) {
          mi = i;
          break;
        }
      }
      if (mi == n) {
        res += n % 2 == 0;
      } else {
        res += mi % 2 == 0;
      }
    }
    cout << res << '\n';
  }
}


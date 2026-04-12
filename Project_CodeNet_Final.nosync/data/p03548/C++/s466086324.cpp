#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z; cin >> x >> y >> z;
  auto f = [&](int n) {
    return (y + z) * n <= x - z;
  };
  int l = 0, r = x / y + 10;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (f(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}

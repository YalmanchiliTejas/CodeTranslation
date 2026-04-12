#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z; cin >> x >> y >> z;
  auto f = [&](int n) {
    return (y + z) * n <= x - z;
  };
  for (int i = x / y; ; i--) {
    if (f(i)) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 1000000000;
  for (int i = 0; i <= max(x, y); i++) {
    int cn = 2 * i;
    int an = (x > i) ? (x - i) : 0;
    int bn = (y > i) ? (y - i) : 0;
    int val = a * an + b * bn + c * cn;
    if (val < ans) {
      ans = val;
    }
  }
  cout << ans << endl;
  return 0;
}
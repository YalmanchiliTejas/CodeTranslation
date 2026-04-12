#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int t1 = a * x + b * y;
  int t2 = c * max(x, y) * 2;
  int t3 = a * (x - min(x, y)) + b * (y - min(x, y)) + c * min(x, y) * 2;
  cout << min(t1, min(t2, t3)) << endl;
}
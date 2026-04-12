#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y, sum = 0;
  cin >> a >> b >> c >> x >> y;
  int mini = min(x, y);
  if (a + b >= c * 2) {
    sum = c * 2 * min(x, y);
    x -= mini;
    y -= mini;
  }
  
  sum += min(a, c*2) * x + min(b, c*2) * y;
  cout << sum << endl;
}
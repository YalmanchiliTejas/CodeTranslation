#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define INF 1000000000

int main() {
  int a, b, c, x, y, i, ans = INF;
  cin >> a >> b >> c >> x >> y;
  for (i = 0; i <= max(x, y); i++) {
    ans = min(ans, 2 * c * i + a * max(0, x - i) + b * max(0, y - i));
  }
  cout << ans << "\n";
  return 0;
}
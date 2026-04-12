#include <iostream>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ans = a * x + b * y;
  int z = max(x, y);
  for (int i = z; i > 0; i--) {
    int t = a * max(x - i, 0) + b * max(y - i, 0) + 2 * c * i;
    ans = min(ans, t);
  }

  cout << ans << endl;

}
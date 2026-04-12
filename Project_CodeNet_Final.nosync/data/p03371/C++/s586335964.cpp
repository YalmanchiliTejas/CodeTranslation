#include <iostream>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  long long ans = 1ll << 55;
  for (int i = 0; i <= 100000; i++) {
    int an = max(0, x - i);
    int bn = max(0, y - i);
    ans = min(ans, (long long)i * 2 * c + an * a + bn * b);
  }
  cout << ans << endl;
}

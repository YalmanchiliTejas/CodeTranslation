#include <iostream>

using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ans = a * x + b * y; 
  for (int cc=0;cc<=100000;cc++) {
    int aa = max(x - cc, 0);
    int bb = max(y - cc, 0);
    
    int sum = aa * a + bb * b + cc * 2 * c;
    ans = min(ans, sum);

    }
  cout << ans << endl;
  return 0;
}

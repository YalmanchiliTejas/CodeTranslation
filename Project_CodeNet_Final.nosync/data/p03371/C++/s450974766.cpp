#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  // abピザは買わない
  if (2 * c >= a + b) {
    cout << a * x + b * y << endl;
  } else { // abピザ買う
    int money = 0;
    int min_xy = min(x, y);
    money += min_xy * 2 * c;
    x -= min_xy;
    y -= min_xy;
    if (x > 0) {
      if (a < 2 * c) {
        money += x * a;
      } else {
        money += 2 * x * c;
      }
    } else {
      if (b < 2 * c) {
        money += y * b;
      } else {
        money += 2 * y * c;
      }
    }
    cout << money << endl;
  }
  return 0;
}
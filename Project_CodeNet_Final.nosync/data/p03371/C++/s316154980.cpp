#include <iostream>
using namespace std;
int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int val = a * x + b * y;
  if (x > y) {
    for (int i = y; i <= x; i++) {
      if (val > (x - i) * a + c * 2 * i) {
        val = (x - i) * a + 2 * c * i;
      }
    }
  } else {
    for (int i = x; i <= y; i++) {
      if (val > (y - i) * b + 2 * i * c) {
        val = (y - i) * b + 2 * i * c;
      }
    }
  }
  cout << val << endl;
  return 0;
}

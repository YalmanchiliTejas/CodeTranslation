#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int result;
  if (a + b > c * 2) {
    result = c * min(x, y) * 2;
  } else {
    result = (a + b) * min(x, y);
  }
  int temp = min(x, y);
  y -= temp;
  x -= temp;
  if (a > c * 2) {
    result += c * x * 2;
  } else {
    result += a * x;
  }
  if (b > c * 2) {
    result += c * y * 2;
  } else {
    result += b * y;
  }
  cout << result << endl;
  return 0;
}

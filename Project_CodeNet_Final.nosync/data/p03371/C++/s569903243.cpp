#include <iostream>
#include <string>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int sum = 0;

  int price1;

  if (a + b < 2 * c) {
    price1 = a + b;
  } else {
    price1 = 2 * c;
  }

  while (x != 0 && y != 0) {
    sum += price1;
    x--;
    y--;
  }

  if (x != 0) {
    if (x * a < 2 * x * c) {
      sum += x * a;
    } else {
      sum += 2 * x * c;
    }
  } else if (y != 0) {
    if (y * b < 2 * y * c) {
      sum += y * b;
    } else {
      sum += 2 * y * c;
    }
  }

  cout << sum << "\n";
  return 0;
}
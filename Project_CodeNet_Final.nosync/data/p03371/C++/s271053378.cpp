#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int a, b, c, x, y;

  cin >> a >> b >> c >> x >> y;

  if ((a + b) > (c * 2)) {
    if (x > y) {
      cout << (y * c * 2) + (x - y) * min(a, c * 2) << endl;
    } else if (x < y) {
      cout << (x * c * 2) + (y - x) * min(b, c * 2) << endl;
    } else {
      cout << (c * 2) * x << endl;
    }
  } else {
    cout << a * x + b * y << endl;
  }

  return 0;
}
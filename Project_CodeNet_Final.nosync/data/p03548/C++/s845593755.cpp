#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  int x, y, z;
  cin >> x >> y >> z;
  for (int i = 0; i < x; i++) {
    int left = x - (y * i);
    int left2 = left - (z * (i + 1));
    if (left2 < 0) {
      cout << (i - 1 < 0 ? 0 : i - 1) << endl;
      return 0;
    }
  }
  return 0;
}
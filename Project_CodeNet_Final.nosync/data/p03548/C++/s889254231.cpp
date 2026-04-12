#include <bits/stdc++.h>

using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int result = 1;
  for (; result < 100000; result++) {
    long temp = result * y + (result - 1) * z + 2 * z;
    if (temp > x) {
      break;
    }
  }
  cout << (result - 1) << endl;
  return 0;
}
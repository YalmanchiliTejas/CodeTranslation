#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int x, y, z, sum = 0;
  cin >> x >> y >> z;
  for (int n = 1; n < 1000000; ++n) {
    if (sum > x) {
      cout << n - 2 << endl;
      break;
    }
    sum = y * n + z * (n + 1);
  }
  return 0;
}


// #define int long long

#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAX = 100000 + 10;

int main() {
  int r, g, b;
  int n;
  cin >> r >> g >> b;
  n = 100 * r + 10 * g + b;
  if (n % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
int main() {
  int A, B, C, X, Y, min = INT_MAX;
  cin >> A >> B >> C >> X >> Y;
  for (int i = 0; i < 100001; i++) {
    int v = 2 * C * i + max(0, X - i) * A + max(0, Y - i) * B;
    if (v < min) min = v;
  }
  cout << min << endl;
  return 0;
}
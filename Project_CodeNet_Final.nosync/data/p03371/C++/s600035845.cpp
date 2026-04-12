#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll price = 0 * 2 * C + max(0, X - 0) * A + max(0, Y - 0) * B;
  for (int i = 1; i < 100001; ++i) {
    ll price_sub = i * 2 * C + max(0, X - i) * A + max(0, Y - i) * B;
    if (price > price_sub) {
      price = price_sub;
    }
  }
  cout << price << endl;
  return 0;
}

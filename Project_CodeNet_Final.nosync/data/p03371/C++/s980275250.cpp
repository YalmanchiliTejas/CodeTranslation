#include <iostream>

using namespace std;

int a, b, c, x, y;

void solve() {
  int cost = 0;
  if (a + b > 2 * c) {
    if (x > y) {
      cost = y * 2 * c + (x - y) * a;
    } else {
      cost = x * 2 * c + (y - x) * b;
    }
    cost = min(cost, max(x, y) * 2 * c);
  } else {
    cost = x * a + y * b;
  }
  cout << cost << endl;
}

int main() {
  cin >> a >> b >> c >> x >> y;
  solve();
}

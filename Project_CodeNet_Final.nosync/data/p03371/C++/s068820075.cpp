#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1001010;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int cost_a = x * a;
  int cost_b = y * b;
  int best = cost_a + cost_b;

  for(int i = 2; (i >> 1L) <= max(x, y); i += 2) {
    int new_cost = i * c + max(x - (i / 2), 0) * a + max(y - (i / 2), 0) * b;
    best = min(best, new_cost);
  }
  cout << best << endl;
}

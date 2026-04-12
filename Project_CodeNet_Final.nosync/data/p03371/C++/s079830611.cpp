#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c, int x, int y) {
  long ans = 1e18;
  for (int i = 0; i <= max(x, y); i++) {
    long sum = 2 * i * c + max(x - i, 0) * a + max(y - i, 0) * b;
    ans = min(ans, sum);
  }
  return ans;
}
int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  cout << solve(a, b, c, x, y) << endl;
}

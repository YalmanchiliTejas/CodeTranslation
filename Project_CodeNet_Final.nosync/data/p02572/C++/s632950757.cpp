/**
 *    author:  DFLMKWR
 */

#include <iostream>

using namespace std;

const int m = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long s = 0, x, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ans += s * x % m;
    ans %= m;
    s = (s + x) % m;
  }
  cout << ans << "\n";
  return 0;
}

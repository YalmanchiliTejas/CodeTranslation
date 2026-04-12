#include <cstdio>
#include <iostream>
using namespace std;

int n, k;

int main() {
  int n, k;
  long long ans = 0;
  cin >> n >> k;
  for (int i = k + 1; i <= n; i ++) {
    int l, r;
    for (int w = 0; w <= n; w ++) {
      l = max(i * w + k, 1); r = min(i * w + i - 1, n);
      if (l > n) break;
      ans += r - l + 1;
      if (r == n) break;
    }
  }
  cout << ans << endl;
  return 0;
}

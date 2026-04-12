#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  for (int b = 1; b <= n; b++) {
      ans += max(b - k, 0) * (n / b) + max(n % b - k + 1, 0);
  }
  if (k == 0) {
      ans -= n;
  }
  cout << ans;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  // 1 <= a, b <= n
  // a % b >= k
  for (int b = 1; b <= n; b++) {
    int p = n/b;
    int add = 0;
    add += p * max(0, b-k);
    add += max(0, n % b - k + 1);
    if (k == 0) { add--; }
    ans += add;
  }

  cout << ans << endl;

  return 0;
}
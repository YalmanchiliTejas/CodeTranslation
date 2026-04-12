#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  for (int ni = k + 1; ni <= n; ni++) {
    ans += n / ni * (ni - k);
    if (n % ni >= k) ans += n % ni - k + 1;
  }
  if (k == 0) ans -= n;
  cout << ans << endl;
  return 0;
}
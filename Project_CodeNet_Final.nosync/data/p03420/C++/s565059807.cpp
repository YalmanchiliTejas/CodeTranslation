#include <bits/stdc++.h>

using namespace std;

void hawawa()
{
  unsigned long long n, k;
  cin >> n >> k;
  unsigned long long ans = 0;
  if (k == 0) {
    cout << n * n << "\n";
    return;
  }
  for (int i = k + 1; i <= n; i++) {
    unsigned long long s = n % i;
    if (k <= s) {
      ans += s - k + 1;
    }
    ans += (i - k) * (n / i);
  }
  cout << ans << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  hawawa();
  return 0;
}
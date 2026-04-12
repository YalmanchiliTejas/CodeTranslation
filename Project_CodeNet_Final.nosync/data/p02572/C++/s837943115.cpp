#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  lint ans = 0;
  const lint MOD = 1e9 + 7;
  int n;
  cin >> n;
  lint sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ans += 1ll * sum * a;
    sum += a;
    ans %= MOD;
    sum %= MOD;
  }
  cout << ans << "\n";
  return 0;
}

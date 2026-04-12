#include <iostream>

using namespace std;

int main() {
  int n;
  long a[200020];
  long mod = 1000000007;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  long long x = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + a[i] * x) % mod;
    x = (x + a[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}

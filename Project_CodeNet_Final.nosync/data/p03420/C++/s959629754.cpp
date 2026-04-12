#include <iostream>
using namespace std;
typedef long long ll;
int main(void) {
  ll n, k;
  ll ans = 0;
  cin >> n >> k;
  if (k == 0) {
    ans = n * n;
  } else {
    for (ll i = k + 1; i <= n; i++) {
      ll quo1 = (n - k) / i;
      ll rem1 = (n - k) % i;
      ll quo2 = (n - i) / i;
      ll rem2 = (n - i) % i;
      ll num1 = (quo1 + 1) * (rem1 + 1) + (quo1 + 1) * quo1 * i / 2;
      ll num2 = (quo2 + 1) * (rem2 + 1) + (quo2 + 1) * quo2 * i / 2;
      ans += (num1 - num2);
    }
  }
  cout << ans << endl;
  return 0;
}
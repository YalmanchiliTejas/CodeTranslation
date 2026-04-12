#include <bits/stdc++.h>
using namespace std;
long long int a[200005];
long long int pre, ans;
const int mod = 7 + 1e9;
int main() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long int i = 0; i < n - 1; i++) {
    pre = (pre + a[i]) % mod;
    ans = (ans + pre * a[i + 1]) % mod;
  }
  cout << ans % mod << endl;
  system("pause");
  return 0;
}

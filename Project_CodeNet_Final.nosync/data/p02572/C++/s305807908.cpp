#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;

  cin >> n;

  vector<int> a(n);

  long long sum = 0;
  int mod = 1e9 + 7;

  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    sum %= mod;
  }

  // find the area of a large square
  long long ans = sum * sum % mod;

  //remove the central square
  for(int i = 0; i < n; i++) {
    ans -= (long long)a[i] * a[i] % mod;
    if(ans < 0)
      ans += mod;
  }

  // divide by 2
  // ans /= 2 with mod 1e9 + 7
  ans *= (mod + 1) / 2;
  ans %= mod;

  cout << ans << endl;
  return 0;
}
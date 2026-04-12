#include <math.h>

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<unsigned long long> a(n);
  vector<ll> rui(n + 1, 0);
  rui[0] = 0;
  rep(i, n) {
    cin >> a[i];
    rui[i + 1] += a[i] + rui[i];
    rui[i + 1] %= MOD;
    // cout << rui[i + 1] << " ";
  }

  unsigned long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (i >= 1) {
      ans += (rui[i] * a[i]) % MOD;
      ans %= MOD;
    }
  }
  cout << ans;
  return 0;
}

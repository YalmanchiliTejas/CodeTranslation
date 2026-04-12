#include <iostream>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int a[200001];

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);    
  int n;
  cin >> n;
  int ans = 0, cur = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cur += a[i];
    cur %= mod;
  }
  for (int i = 0; i < n; ++i) {
    cur -= a[i];
    cur %= mod;
    cur += mod;
    cur %= mod;
    ans += a[i] * cur;
    ans %= mod;
  }
  cout << ans;
  return 0;
}

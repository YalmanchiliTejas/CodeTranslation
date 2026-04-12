#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    sum %= mod;
  }

  ll ans = 0;

  for (int i = 0; i < n; i++) {
    sum -= a[i];
    sum = (sum + mod) % mod;
    ans += (a[i] * sum) % mod;
    ans %= mod;
  }

  cout << ans << endl;
}
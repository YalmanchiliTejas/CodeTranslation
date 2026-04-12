#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll &i : a)
    cin >> i;
  ll sum = a.back(), ans = 0;
  for (int i = n - 2; i >= 0; i--) {
    ans = (ans + a[i] * sum) % mod;
    sum = (sum + a[i]) % mod;
  }
  cout << ans;
}
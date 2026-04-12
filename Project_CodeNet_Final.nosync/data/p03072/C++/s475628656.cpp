#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  ll n;
  cin >> n;
  vector<ll> h(n, 0);
  for (ll i = 0; i < n; ++i) {
    cin >> h[i];
  }

  ll low = 0;
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    if (h[i] >= low) {
      ans++;
      low = h[i];
    }
  }

  cout << ans << endl;

  return 0;
}
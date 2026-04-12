#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
const ll mod = (ll)1e9 + 7;

int main() {
  int n;
  cin >> n;
  ll sum = 0, dsum = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    sum = (sum + a) % mod;
    dsum = (dsum + (a * a) % mod) % mod;
  }
  sum = (sum * sum) % mod;
  if (sum >= dsum)
    sum -= dsum;
  else
    sum += mod - dsum;
  sum = (sum * (ll)(5e8 + 4)) % mod;
  cout << sum << endl;
  return 0;
}

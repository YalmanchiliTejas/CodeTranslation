#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 1e9;
  for (int i = 0; i <= 1e6; i+=2) {
    ll cost = i * c;
    cost += (i / 2 < x ? (x - i / 2) * a : 0);
    cost += (i / 2 < y ? (y - i / 2) * b : 0);
    ans = min(cost, ans);
  }
  cout << ans << endl;
  return 0;
}
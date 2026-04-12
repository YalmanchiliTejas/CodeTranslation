#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = LLONG_MAX;
  for(ll i = 0; i<= 100000; i++) {
    ans = min(ans, a*max(x-i,(ll)0)+b*max(y-i,(ll)0)+2*c*i);
  }
  cout << ans << endl;
  return 0;
}
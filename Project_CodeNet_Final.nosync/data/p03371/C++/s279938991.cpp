#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  ll ans = 1e9;
  if (X >= Y) {
    ll x[3] = {0, X-Y, X};
    for (int a = 0; a < 3; a++) {
      ll y[2] = {0, Y};
      for (int b = 0; b < 2; b++) {
        ll c = max(X-x[a], Y-y[b])*2;
        ans = min(ans, A*x[a]+B*y[b]+C*c);
      }
    }
  } else {
    ll y[3] = {0, Y-X, Y};
    for (int b = 0; b < 3; b++) {
      ll x[2] = {0, X};
      for (int a = 0; a < 2; a++) {
        ll c = max(X-x[a], Y-y[b])*2;
        ans = min(ans, A*x[a]+B*y[b]+C*c);
      }
    }
  }
  cout << ans << endl;
}

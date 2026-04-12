#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans = 0;
  if (A + B > 2 * C) {
    ans += min(X, Y) * 2 * C;
  } else {
    ans += A * min(X, Y);
    ans += B * min(X, Y);
  }

  if(X > Y) {
    if (A > 2 * C) {
      ans += (X - Y) * 2 * C;
    } else {
      ans += A * (X - Y);
    }
  } else if (X < Y) {
    if (B > 2 * C) {
      ans += (Y - X) * 2 * C;
    } else {
      ans += B * (Y - X);
    }
  }
  cout << ans << endl;
  return 0;
}
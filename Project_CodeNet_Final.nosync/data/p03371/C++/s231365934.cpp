#include <bits/stdc++.h>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < (n); i++)

using namespace std;

void solve() {
  long A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  long ans = 0;
  ans += min(A+B, 2*C) * min(X, Y);
  if (X > Y) ans += min(A, 2*C) * (X-Y);
  if (X < Y) ans += min(B, 2*C) * (Y-X);
  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}

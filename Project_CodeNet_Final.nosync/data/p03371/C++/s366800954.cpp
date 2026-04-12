#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve(int A, int B, int C, long X, long Y) {
  long ans(0);
  if (X > Y)
    ans = Y * 2 * C + (X - Y) * A;
  else
    ans = X * 2 * C + (Y - X) * B;
  ans = min(ans, A * X + B * Y);
  ans = min(ans, max(X, Y) * 2 * C);
  cout << ans << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, C;
  long X, Y;
  cin >> A >> B >> C >> X >> Y;

  solve(A, B, C, X, Y);

  return 0;
}

#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans1, ans2, ans3, ans4;
  ans1 = A * X + B * Y;
  ans2 = C * 2 * max(X, Y);
  ans3 = C * 2 * X + max((Y - X), 0) * B;
  ans4 = C * 2 * Y + max((X - Y), 0) * A;

  // cout << ans1 << ":" << ans2 << ":" << ans3 << ":" << ans4 << endl;

  cout << min(min(min(ans1, ans2), ans3), ans4) << endl;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
#define __lcm(a, b) std::__detail::__lcm(a, b)
typedef long long ll;
const long mod = 1e9 + 7;

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  long A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  long ans = 0;
  long min_ = min({A, B, C * 2});
  if (A + B > C * 2) {
    int n = abs(X - Y);
    if (X > Y) {
      ans += min(C * 2 * max(X, Y), C * 2 * min(X, Y) + A * n);
    } else {
      ans += min(C * 2 * max(X, Y), C * 2 * min(X, Y) + B * n);
    }
  } else if (min_ == A) {
    ans += A * X;
    ans += min(B, C * 2) * Y;
  } else if (min_ == B) {
    ans += B * Y;
    ans += min(A, C * 2) * X;
  } else {
    ans += C * 2 * max(X, Y);
  }
  cout << ans << endl;
  return 0;
}

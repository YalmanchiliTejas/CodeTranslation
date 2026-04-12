#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) stable_sort(a.begin(), a.end())
#define rsort(a) stable_sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
#define join(a, d) accumulate(a.begin() + 1, a.end(), a[0], [](string s, string t) {return s + d + t;})
#define all(a) a.begin(), a.end()
// #define __lcm(a, b) std::__detail::__lcm(a, b)
typedef long long ll;
const long mod = 1e9 + 7;

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = 0;
  if ((A + B) > C * 2) {
    ans += (C * 2) * min(X, Y);
    int x = max(0, X - Y);
    int y = max(0, Y - X);
    X = x;
    Y = y;
  }
  if (X) {
    ans += min(A, C * 2) * X;
  }
  if (Y) {
    ans += min(B, C * 2) * Y;
  }
  cout << ans << endl;
  return 0;
}

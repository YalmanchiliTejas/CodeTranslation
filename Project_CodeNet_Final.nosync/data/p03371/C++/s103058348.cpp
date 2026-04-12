#include <bits/stdc++.h>
using namespace std;
#define long long long
#define read cin >>
#define echo cout <<
#define fin << endl
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)

// for debug macro
bool global_debug_flag = true;
#define DEBUG(val) \
  if (global_debug_flag) cout << #val << " = " << val << endl

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  c *= 2;
  int ans = 5000 * 100000 + 5000 * 100000;
  REP(i, 100001) {
    int rest_a = max(0, x - i);
    int rest_b = max(0, y - i);
    ans = min(ans, c * i + rest_a * a + rest_b * b);
  }
  cout << ans << endl;
}
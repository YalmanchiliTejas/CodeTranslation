#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans = min(X, Y) * 2 * C;
  int tmX = X - ans / 2 / C, tmY = Y - ans / 2 / C;
  ll ans1=ans + max(tmX, 0) * A + max(tmY, 0) * B;//併用
  ll ans2 = max(X, Y) * 2 * C;//全C
  ll ans3 = A * X + Y * B;//Cなし
  ans = 0;
  ans = min(ans1, ans2);
  ans = min(ans, ans3);
  cout << ans << endl;
}
#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll cnt_p[52], cnt_all[52];

ll recursion(ll n, ll x) {
  if (n == 0) {
    if (x <= 0)
      return 0;
    else
      return 1;
  }
  if (x - 1 <= cnt_all[n - 1]) {
    return recursion(n - 1, x - 1);
  } else {
    return cnt_p[n - 1] + 1 + recursion(n - 1, x - 2 - cnt_all[n - 1]);
  }
}
int main() {
  ll N, X;
  cin >> N >> X;
  cnt_p[0] = 1;
  cnt_all[0] = 1;
  for (int i = 1; i <= N; i++) {
    cnt_p[i] = 2 * cnt_p[i - 1] + 1;
    cnt_all[i] = 2 * cnt_all[i - 1] + 3;
  }
  ll ans = recursion(N, X);
  cout << ans << endl;
  return 0;
}
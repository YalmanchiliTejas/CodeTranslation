#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < n; ++i)

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  if (x == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 1) {
    cout << x << endl;
    return 0;
  }
  if (n == 2) {
    cout << x + x * x % m << endl;
    return 0;
  }

  ll y = x;
  vector<ll> used(m + 1);
  ll start = 0, end = 0;
  rep(i, 0, n) {
    used[x]++;
    end = x;
    x = x * x % m;
    if (used[x] == 1) {
      start = x;
      break;
    }
  }
  ll ans = 0;
  ll now = y;
  while (n > 0 && now != start) {
    ans += now;
    now = now * now % m;
    --n;
  }
  ll loop = 1;
  ll loop_sum = now;
  now = now * now % m;
  ll cnt = 1000000;
  while (cnt > 0 && now != start) {
    loop_sum += now;
    now = now * now % m;
    ++loop;
    --cnt;
  }

  if (n <= 0 || x == 0) {
    cout << ans << endl;
    return 0;
  }
  ans += n / loop * loop_sum;
  n %= loop;
  rep(i, 0, n) {
    ans += x;
    x = x * x % m;
  }
  cout << ans << endl;
  return 0;
}

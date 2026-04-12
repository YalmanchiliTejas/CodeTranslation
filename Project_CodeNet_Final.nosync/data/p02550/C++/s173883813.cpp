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
#define rep(i, j, n) for (int i = j; i < (int)(n); ++i)
#define rrep(i, j, n) for (int i = (int)(n)-1; j <= i; --i)

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  vector<bool> used(m * 2);
  vector<ll> one_cycle;

  int start = 0;
  ll now = x;
  rep(i, 0, m) {
    used[now] = true;
    one_cycle.push_back(now);
    now = now * now % m;
    if (used[now]) {
      rep(j, 0, one_cycle.size()) if (one_cycle[j] == now) {
        start = j;
        break;
      }
      break;
    }
  }

  ll s1 = 0, s2 = 0, loop = one_cycle.size() - start;
  rep(i, 0, start) s1 += one_cycle[i];
  rep(i, start, one_cycle.size()) s2 += one_cycle[i];
  ll ans = s1 + (n - start) / loop * s2;
  rep(i, 0, (n - start) % loop) {
    ans += now;
    now = now * now % m;
  }
  cout << ans << endl;
  return 0;
}

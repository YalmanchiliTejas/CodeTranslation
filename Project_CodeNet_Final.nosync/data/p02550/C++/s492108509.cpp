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

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  vector<bool> used(m * 2);
  vector<ll> one_cycle;

  int start = 0;
  ll now = x;
 	for(int i = 0; i < n; ++i) {
    used[now] = true;
    one_cycle.push_back(now);
    now = now * now % m;
    if (used[now]) {
      for(int j = 0; j < (int)one_cycle.size(); ++j) if (one_cycle[j] == now) {
        start = j;
        break;
      }
      break;
    }
  }

  ll s1 = 0, s2 = 0, loop = one_cycle.size() - start;
  for(int i = 0; i < start; ++i) s1 += one_cycle[i];
  for(int i = start; i < one_cycle.size(); ++i) s2 += one_cycle[i];
  ll ans = s1 + (n - start) / loop * s2;
  for(int i = 0; i < (n - start) % loop; ++i) {
    ans += now;
    now = now * now % m;
  }
  cout << ans << endl;
  return 0;
}

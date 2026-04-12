#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <set>
#include <utility>
using namespace std;
using ll = long long;

template <typename T>
void print_vec(const vector<T> &v) {
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    if (i > 0) cout << ' ';
    cout << v[i];
  }
  cout << '\n';
}

int main() {

  ll n, x, m;
  cin >> n >> x >> m;
  ll a = x;
  ll r = a;
  if (n < m) {
    for (ll i = 2; i <= n; ++i) {
      a = a * a % m;
      r += a;
    }
    cout << r << '\n';
    return 0;
  }

  vector<ll> exist(m + 2, false);
  vector<ll> mod;
  mod.push_back(x);
  exist[x] = true;
  ll loop_val = -1;
  for (ll i = 2; i <= m + 1; ++i) {
    a = a * a % m;
    if (!exist[a]) {
      exist[a] = true;
      mod.push_back(a);
    } else {
      loop_val = a;
      break;
    }
  }
  ll loop_id = find(mod.begin(), mod.end(), loop_val) - mod.begin();
  ll sz = mod.size() - loop_id;
  ll loop_sum = accumulate(mod.begin() + loop_id, mod.end(), 0ll);
  ll ans = accumulate(mod.begin(), mod.begin() + loop_id, 0ll);
  ll re = n - loop_id;
  ans += re / sz * loop_sum + accumulate(mod.begin() + loop_id, mod.begin() + loop_id + re % sz, 0ll);
  cout << ans << '\n';
  return 0;
}

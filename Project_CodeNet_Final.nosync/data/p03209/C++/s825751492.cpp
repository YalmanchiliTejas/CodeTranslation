#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <sstream>

using namespace std;
typedef long long ll;
vector<ll> all(55);
vector<ll> p(55);

ll search(ll n, ll x) {
  if (x <= 0) {
    return 0;
  }
  if (n == 0) {
    return 1;
  }
  if (all[n] == x) {
    return p[n];
  }
  ll mid = (all[n] + 1) / 2;
  if (mid == x) {
    return p[n - 1] + 1;
  }
  if (mid > x) {
    return search(n - 1, x - 1);
  }
  return p[n - 1] + 1 + search(n - 1, x - all[n - 1] - 2);
}

int main() {
  ll n, x;
  cin >> n >> x;
  
  // 初期値
  all[0] = 1;
  p[0] = 1;
  for (ll i = 1; i <= n; i++) {
    all[i] = all[i - 1] * 2 + 3;
    p[i]   = p[i - 1] * 2 + 1;
  }
  cout << search(n, x) << endl;
  return 0;
}

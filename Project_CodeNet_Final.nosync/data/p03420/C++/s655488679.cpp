#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <numeric>
#include <cassert>
#include <functional>
using namespace std;

typedef unsigned long long int llui;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
constexpr double pi = 3.141592653589793238462643383279502884L;

// TODO: Mod class

const int sz = 1e5;

int main() {
  ios::sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  ll ans = 0;

  for (ll p = k + 1; p <= n; ++p) {
    ll init = (n - k) / p + 1;
    ll j = p - k;
    ll rr = (n - k) % p + 1;
    ans += min(j, rr) * init;
    j -= min(j, rr);
    ll minus = (j + p - 1) / p;
    if (minus <= init) {
      ans += (j % p) * (init - minus);
    }
    j -= j % p;
    ll cc = j / p;
    cc = min(init, cc);
    ans += init * j - p * ((1 + cc) * cc) / 2;
  }
  if (k == 0) {
    ans -= n;
  }
  cout << ans << endl;
}

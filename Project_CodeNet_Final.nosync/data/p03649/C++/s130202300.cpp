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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll& x : a) {
    cin >> x;
  }

  ll l = -1;
  ll r = 50 * 1e16 + 1;

  while (l < r) {
    ll m = l + (r - l) / 2;
    bool ok = false;
    for (int i = 0; i < n; ++i) {
      ll d = m - i;
      for (ll x : a) {
        x += m - i;
        if (x < n) {
          continue;
        }
        d -= (x + 1) / (n + 1);
        if (d < 0) {
          break;
        }
      }
      if (d >= 0) {
        ok = true;
        break;
      }
    }
    if (ok) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  cout << r << endl;
}

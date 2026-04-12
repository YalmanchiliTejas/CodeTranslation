#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;

ll lcm(ll n, ll m) { return (n / __gcd(n, m)) * m; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll h, w;
  cin >> h >> w;
  vector<string> mp(h);
  rep(i, h) cin >> mp[i];
  ll x = 0, y = 0;

  ll pre = -1;
  while (x < w || y < h) {
    bool rig = x + 1 < w && mp[y][x + 1] == '#';
    bool lef = x - 1 >= 0 && mp[y][x - 1] == '#';
    bool dow = y + 1 < h && mp[y + 1][x] == '#';
    bool upp = y - 1 >= 0 && mp[y - 1][x] == '#';
    bool chk = (pre == 0 && !upp) || (pre == 1 && !lef) || pre == -1;

    if (x == w - 1 && y == h - 1) {
      if (!chk) {
        puts("Impossible");
        return 0;
      } else
        break;
    }

    if (chk && rig && !dow) {
      x++;
      pre = 0;
    } else if (chk && !rig && dow) {
      y++;
      pre = 1;
    } else {
      puts("Impossible");
      return 0;
    }
  }

  puts("Possible");
  return 0;
}

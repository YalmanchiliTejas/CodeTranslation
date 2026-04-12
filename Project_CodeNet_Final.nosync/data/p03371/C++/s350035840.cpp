#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define REP(X, Y, Z) for (ll(X) = (Y); (X) < (Z); (X)++)
#define REV(X, Y, Z) for (ll(X) = (Y); (X) > (Z); (X)--)

using namespace std;
using ll = long long;
using dll = deque<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using usll = unordered_set<ll>;
using umll = unordered_map<ll, ll>;
using sll = stack<int>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll kMod = 1e9 + 7;

ll gcd(ll a, ll b) {
  if (a < b) {
    return gcd(b, a);
  }
  ll c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

void init() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

int main() {
  init();

  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  ll mi = kMod * kMod;
  REP(i, 0, 100001) {
    ll su = i * 2 * C + A * max(ll(0), X - i) + B * max(ll(0), Y - i);
    if (mi > su) {
      mi = su;
    }
  }
  cout << mi << endl;

  return 0;
}

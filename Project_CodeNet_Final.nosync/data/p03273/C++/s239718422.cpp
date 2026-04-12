#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
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

  ll H, W;
  cin >> H >> W;
  vector<vector<char>> A;
  REP(i, 0, H) {
    string s;
    cin >> s;
    vector<char> c(W);
    bool all_dot = true;
    REP(j, 0, s.size()) {
      c[j] = s[j];
      if (c[j] == '#') {
        all_dot = false;
      }
    }
    if (!all_dot) {
      A.emplace_back(c);
    }
  }

  vll h_ok(A.size(), 0);
  vll w_ok(A[0].size(), 0);
  REP(i, 0, A.size()) {
    REP(j, 0, A[0].size()) {
      if (A[i][j] == '#') {
        h_ok[i] = 1;
        w_ok[j] = 1;
      }
    }
  }

  REP(i, 0, A.size()) {
    if (!h_ok[i]) { continue; }
    REP(j, 0, A[i].size()) {
      if (!w_ok[j]) { continue; }
      cout << A[i][j];
    }
    cout << endl;
  }

  return 0;
}

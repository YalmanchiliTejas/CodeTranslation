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

  ll H, W;
  cin >> H >> W;
  vector<vll> A(H);
  REP(i, 0, H) {
    string w;
    cin >> w;
    vll a(W);
    REP(j, 0, W) {
      if (w[j] == '#') {
        a[j] = 1;
      } else {
        a[j] = 0;
      }
    }
    A[i] = a;
  }

  ll first = -1;
  ll last = -1;
  REP(w, 0, W) {
    if (first == -1 && A[0][w] == 1) {
      first = w;
    }
    if (last == -1 && A[0][w] == 1) {
      last = w;
    }
    if (last != -1 && A[0][w] == 1) {
      if (w - last > 1) {
        cout << "Impossible" << endl;
        return 0;
      }
      last = w;
    }
  }

  REP(h, 1, H) {
    bool is_f = false;
    ll f = last;
    ll l = 0;
    REP(w, 0, W) {
      if (!is_f && A[h][w] == 1) {
        f = w;
        l = w;

        is_f = true;
        if (last != f) {
          cout << "Impossible" << endl;
          return 0;
        }
      }
      if (A[h][w] == 1) {
        if (w - l > 1) {
          cout << "Impossible" << endl;
          return 0;
        }
        l = w;
      }
    }
    last = l;
  }
  cout << "Possible" << endl;

  return 0;
}

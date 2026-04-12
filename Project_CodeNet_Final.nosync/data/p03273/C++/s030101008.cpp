#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 60;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll h, w;
  cin >> h >> w;
  vector<string> data(h);
  rep(i, h) cin >> data[i];
  vector<ll> r(h, 0), c(w, 0);
  rep(i, h) {
    rep(j, w) {
      if (data[i][j] == '#') {
        r[i]++;
        c[j]++;
      }
    }
  }
  rep(i, h) {
    if (r[i] == 0) continue;
    rep(j, w) {
      if (c[j]) cout << data[i][j];
    }
    cout << endl;
  }
  return 0;
}

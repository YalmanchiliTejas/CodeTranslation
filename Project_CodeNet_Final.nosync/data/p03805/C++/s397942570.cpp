#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <iterator>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

vvll edges;

ll dfs(ll i, V<bool> visited) {
  bool all_visited = true;
  REP(i, visited.size()) if (!visited[i]) all_visited = false;
  if (all_visited) return 1;

  ll c = 0;
  REP(j, edges[i].size()) {
    if (visited[edges[i][j]]) continue;
    visited[edges[i][j]] = true;
    c += dfs(edges[i][j], visited);
    visited[edges[i][j]] = false;
  }
  return c;
}

int main() {
  ll n, m; cin >> n >> m;
  edges.resize(n);
  REP(i, m) {
    ll a, b; cin >> a >> b;
    edges[a-1].push_back(b-1);
    edges[b-1].push_back(a-1);
  }

  V<bool> visited(n, false);
  visited[0] = true;
  ll ans = dfs(0, visited);
  cout << ans << endl;
  return 0;
}

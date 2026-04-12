#include <algorithm>
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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
ll INF = 1000000000;

ll dfs(int idx, int n, int status, vvl& g) {
  if (status == (1 << n) - 1) {
    return 1;
  }
  ll ans = 0;
  for (auto& v : g[idx]) {
    if ((status >> v) & 1) {
      continue;
    } else {
      ans += dfs(v, n, (status | (1 << v)), g);
    }
  }
  return ans;
}

int main() {
  //
  ll n, m;
  cin >> n >> m;
  vvl g(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ll ans = dfs(0, n, 1, g);
  cout << ans << endl;
  return 0;
}

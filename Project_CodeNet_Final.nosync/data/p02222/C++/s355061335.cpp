#include <bits/stdc++.h>

using namespace std;

using ll = std::int64_t;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
std::vector<std::vector<ll>> p;

struct TreeDP {
  using dp_t = std::vector<std::map<ll, ll>>;
  const std::vector<std::vector<ll>> &tree;
  const std::size_t sz;
  dp_t dp;

  TreeDP(const std::vector<std::vector<ll>> &tree) : tree(tree), sz(tree.size()), dp(sz) {}

  ll dfs1(ll cur, ll pre) {
    ll ret = 0;
    for (ll nxt : tree[cur])
      if (nxt != pre) {
        ll res = dfs1(nxt, cur);
        dp[cur][nxt] = res;
        ret = std::max(ret, res);
      }
    return ret + 1;
  }

  void dfs2(ll cur, ll pre, ll plen) {
    if (0 <= plen) dp[cur][pre] = plen;
    std::vector<std::pair<ll, ll>> lenv;
    for (ll nxt : tree[cur]) lenv.emplace_back(dp[cur][nxt], nxt);

    std::sort(lenv.rbegin(), lenv.rend());
    for (ll nxt : tree[cur])
      if (nxt != pre) {
        ll a, b;
        std::tie(a, b) = lenv[0];
        if (b == nxt) {
          if (2 <= lenv.size()) std::tie(a, b) = lenv[1];
          else a = 0;
        }
        dfs2(nxt, cur, a + 1);
      }
  }

  dp_t solve() {
    dfs1(0, -1);
    dfs2(0, -1, -1);
    return dp;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  p.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  TreeDP t(p);
  auto r = t.solve();
  int diameter = 0, ng = 0;
  for (int i = 0; i < n; i++) {
    vector<int> d;
    for (auto &&j : r[i]) {
      d.push_back(j.second);
    }
    sort(d.rbegin(), d.rend());
    if (d.size() >= 2) {
      diameter = max(diameter, (int) (d[0] + d[1]));
    }
    if (d.size() >= 3) {
      ng = max(ng, (int) min(d[0] * 2 - 1, d[0] + d[2]));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i <= 2) {
      cout << 1;
    } else {
      if (i <= ng) {
        cout << 0;
      } else {
        cout << 1;
      }
    }
  }
  cout << endl;

  return 0;
}


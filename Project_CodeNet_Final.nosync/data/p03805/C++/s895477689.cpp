#include <bits/stdc++.h>

#define fi first
#define se second
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int(v.size())
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n, m) for (ll i = n; i <= (m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (m); --i)

template<class T, class U> void chmax(T &a, U b) { if (a < b) a = b; }
template<class T, class U> void chmin(T &a, U b) { if (b < a) a = b; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

int n, m, ans;

void dfs(int cur, vi visit, const vector<vi> &edge)
{
  visit[cur] = 1;

  bool end = true;
  rep(i, n) if (visit[i] == 0) end = false;

  if (end) {
    ++ans;
    return;
  }

  for (auto next : edge[cur]) {
    if (visit[next]) continue;
    dfs(next,visit,edge);
  }
}

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  vi visit(n,0);
  vector<vi> edge(n);

  rep(i, m) {
    int a, b; cin >> a >> b;
    edge[a-1].emplace_back(b-1);
    edge[b-1].emplace_back(a-1);
  }

  dfs(0,visit,edge);
  cout << ans << endl;
  
  return (0);
}
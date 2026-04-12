#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = (1 << 29);
const long long INFL = (1LL<<60);
const double eps = (1e-9);

int n, m;    // n: nodes, m: edges
vector<vector<int>> nodes(9);

int ans = 0;

void dfs(int v, vector<int>* visited)
{
  visited->push_back(v);
  if (visited->size() == n) {
    ans++;
    visited->pop_back();
    return;
  }
  for (int i : nodes[v]) {
    if (find(visited->begin(), visited->end(), i) == visited->end()) {
      dfs(i, visited);
    }
  }
  visited->pop_back();
  return;
}

int main(void)
{
  cin >> n >> m;

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    nodes[a].push_back(b);
    nodes[b].push_back(a);
  }
  vector<int> visited;

  dfs(1, &visited);

  cout << ans << endl;

  return 0;
}

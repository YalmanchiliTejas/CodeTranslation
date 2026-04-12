#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = int64_t;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1'001'001'001;
const ll INFL = (1LL<<60);
const double eps = (1e-9);

const ll mod = 1e9 + 7;

void warshall_floyd(const int& n, vector<vector<int>>& d) {
  rep(k, n) rep(i, n) rep(j, n) chmin(d[i][j], d[i][k] + d[k][j]);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> e(8, vector<int>(8, 0));
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    e[a][b] = 1;
    e[b][a] = 1;
  }

  vector<int> v;
  for (int i = 1; i < n; i++) {
    v.push_back(i);
  }

  ll ans = 0;
  do {
    int prev = 0;
    bool flag = true;
    for (int i = 0; i < n-1; i++) {
      if (e[prev][v[i]] == 0) {
        flag = false;
        break;
      }
      prev = v[i];
    }
    if (flag) ans++;
  } while (next_permutation(v.begin(), v.end()));

  cout << ans << endl;

  return 0;
}

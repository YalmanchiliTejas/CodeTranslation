#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
constexpr int INF = 1e9;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<string> a;
  rep(i, h) {
    string s;
    cin >> s;
    for (char&c : s) {
      if (c == '#') {
        a.push_back(s);
        break;
      }
    }
  }

  set<int> cols;
  rep(j, w) {
    int flag = true;
    rep(i, a.size()) {
      if (a[i][j] == '#') {
        flag = false;
        break;
      }
    }
    if (flag) cols.insert(j);
  }

  rep(i, a.size()) {
    rep(j, w) {
      if (cols.count(j) > 0) continue;
      printf("%c", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}

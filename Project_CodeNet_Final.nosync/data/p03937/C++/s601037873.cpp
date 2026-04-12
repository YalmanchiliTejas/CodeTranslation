#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

const ll INF = 1e9;
const long long INFL = 1LL<<60;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> a(h);
  rep(i, h) cin >> a[i];

  // 1. # の数は h + w - 1 であること
  int cnt = 0;
  rep(i, h) rep(j, w) if (a[i][j] == '#') cnt++;
  if (cnt != h + w - 1) {
    puts("Impossible");
    return 0;
  }

  queue<P> q;
  q.push({0, 0});

  while (!q.empty()) {
    P now = q.front(); q.pop();
    rep(i, 2) {
      int nh = now.first + dx[i];
      int nw = now.second + dy[i];
      if (h <= nh || w <= nw || a[nh][nw] != '#') continue;
      if (nh == h - 1 && nw == w - 1) {
        puts("Possible");
        return 0;
      }
      q.push({nh, nw});
    }
  }

  puts("Impossible");

  return 0;
}
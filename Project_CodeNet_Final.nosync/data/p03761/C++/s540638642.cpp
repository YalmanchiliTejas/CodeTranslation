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
const int INF = 1e9;
const long long INFL = 1LL<<60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  map<char, int> mp;
  rep(i, n) {
    map<char, int> m;
    string s; cin >> s;
    for (char& c : s) {
      m[c]++;
    }
    if (i == 0) mp = m;
    for (char c = 'a'; c <= 'z'; c++) {
      chmin(mp[c], m[c]);
    }
  }

  for (char c = 'a'; c <= 'z'; c++) {
    rep(i, mp[c]) printf("%c", c);
  }
  printf("\n");

  return 0;
}

#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  REP(i, H) cin >> a[i];
  set<int> row, col;
  REP(j, W){
    if(a[0][j] == '.'){
      bool f = true;
      REP(i, H) if(a[i][j] == '#') f = false;
      if(f) col.insert(j);
    }
  }
  REP(i, H){
    if(a[i][0] == '.'){
      bool f = true;
      REP(j, W) if(a[i][j] == '#') f = false;
      if(f) row.insert(i);
    }
  }
  vector<string> ans;
  REP(i, H){
    if(row.count(i)) continue;
    string s;
    REP(j, W){
      if(col.count(j)) continue;
      s += a[i][j];
    }
    if(!s.empty()) ans.emplace_back(s);
  }
  REP(i, ans.size()) cout << ans[i] << endl;
  return 0;
}
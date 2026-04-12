#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef pair<int, int> P;
const int H = 10;
const int W = 10;

void disp(vector< vector<int> > &v){
  cout <<"----------" <<endl;
  REP(i, H){
    REP(j, W) cout <<v[i][j];
    cout <<endl;
  }
}

void shoot(int y, int x, vector< vector<int> > &v){
  v[y][x] = !v[y][x];
  if(y + 1 < H) v[y + 1][x] = !v[y + 1][x];
  if(y - 1 > -1) v[y - 1][x] = !v[y - 1][x];
  if(x + 1 < W) v[y][x + 1] = !v[y][x + 1];
  if(x - 1 > -1) v[y][x - 1] = !v[y][x - 1];
}

vector<P> change(vector< vector<int> > &v){
  vector<P> res;
  FOR(y, 1, v.size()){
    REP(x, v[y].size()){
      if(v[y - 1][x] == 1){
        shoot(y, x, v);
        res.push_back(P(y, x));
      }
    }
  }
  return res;
}

bool check(vector< vector<int> > &v){
  REP(i, v.size()) REP(j, v[i].size()) if(v[i][j] == 1) return false;
  return true;
}

vector<P> solve(){
  vector< vector<int> > v(H, vector<int>(W));
  REP(i, H) REP(j, W) cin >>v[i][j];
  vector<P> res;
  REP(b, (1 << W)){
    vector< vector<int> > vv = v;
    vector<P> tmp;
    REP(i, W){
      if(!(1 & (b >> i))) continue;
      shoot(0, i, vv);
      tmp.push_back(P(0, i));
    }
    vector<P> ans = change(vv);
    REP(i, tmp.size()) ans.push_back(tmp[i]);
    if(check(vv)){ res = ans; break; }
  }
  return res;
}

int main() {
  int N; cin >>N;
  while(N--){
    vector<P> r = solve();
    vector< vector<int> > ans(H, vector<int>(W, 0));
    REP(i, r.size()) ans[r[i].first][r[i].second] = 1;
    REP(i, H){
      REP(j, W) cout <<(j != 0 ? " ": "") <<ans[i][j];
      cout <<endl;
    }
  }
  return 0;
}
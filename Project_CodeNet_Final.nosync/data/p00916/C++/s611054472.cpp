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
typedef complex<double> P;
const int MAX_YX = 110;
const int INF = 1000000000;

long long int v[MAX_YX][MAX_YX];
int my[] = {0, 0, 1, -1};
int mx[] = {1, -1, 0, 0};

void dfs(int y, int x, long long int t){
  v[y][x] = -1;
  REP(i, 4){
    int ny = y + my[i], nx = x + mx[i];
    if(ny >= 0 && nx >= 0 && ny < MAX_YX && nx < MAX_YX && v[ny][nx] == t) dfs(ny, nx, t);
  }
}

int solve(){
  int res = 0;
  REP(i, MAX_YX){
    REP(j, MAX_YX){
      if(v[i][j] == -1) continue;
      ++res;
      dfs(i, j, v[i][j]);
    }
  }
  return res;
}

int main(){
  int N;
  while(cin >>N && N){
    memset(v, 0, sizeof(v));
    vector<int> L, T, R, B;
    set<int> Ys, Xs;
    REP(i, N){
      int l, t, r, b;
      cin >>l >>t >>r >>b;
      L.push_back(l); T.push_back(t); R.push_back(r); B.push_back(b);
      Ys.insert(t); Ys.insert(b); Xs.insert(l); Xs.insert(r);
    }
    Ys.insert(-1); Ys.insert(INF);
    Xs.insert(-1); Xs.insert(INF);
    vector<int> Y(Ys.begin(), Ys.end());
    vector<int> X(Xs.begin(), Xs.end());
    REP(i, N){
      int xl = lower_bound(X.begin(), X.end(), L[i]) - X.begin();
      int xr = lower_bound(X.begin(), X.end(), R[i]) - X.begin();
      int yt = lower_bound(Y.begin(), Y.end(), T[i]) - Y.begin();
      int yb = lower_bound(Y.begin(), Y.end(), B[i]) - Y.begin();
      FOR(x, xl, xr) FOR(y, yb, yt) v[x][y] |= (1LL << i);
    }
    cout <<solve() <<endl;
  }
  return 0;
}
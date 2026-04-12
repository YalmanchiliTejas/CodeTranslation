#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

// constexpr int INF = 1e9;
constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;
int H, W;
vector<string> A;
vector<vector<bool>> homon;
bool ans = true;
int dx[] = {0, 1};
int dy[] = {1, 0};
void dfs(int h, int w){
  homon[h][w] = true;
  if(h==H-1 && w==W-1) return;
  REP(i, 2){
    int nh = h + dy[i], nw =w + dx[i];
    if(nh >= H || nw >= W) continue;
    if(A[nh][nw] == '#'){
      dfs(nh, nw);
      return;
    }
  }
}
int main(){
  cin >> H >> W;
  A.resize(H);
  homon.resize(H, vector<bool>(W, false));
  REP(i, H){
    cin >> A[i];
  }
  dfs(0, 0);
  REP(i, H){
    REP(j, W){
      if(A[i][j] == '#' && !homon[i][j]){
        ans = false;
      }
    }
  }
  if(ans){
    cout << "Possible" << endl;
  }
  else{
    cout << "Impossible" << endl;
  }

  return 0;
}

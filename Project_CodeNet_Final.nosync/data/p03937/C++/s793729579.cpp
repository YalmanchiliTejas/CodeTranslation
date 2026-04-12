#include <bits/stdc++.h>
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define IFOR(i, m, n) for(int i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
/* テンプレートここまで */

int main() {
  int H, W; cin >> H >> W;
  vector<string> grid(H);
  REP(i, H) cin >> grid[i];

  int sharp = 0;
  REP(i, H) REP(j, W){
    if(grid[i][j] == '#') sharp++;
  }

  int d[2] = {1, 0};

  queue<pair<int,int> > q;
  q.push({0,0});

  int sharp_cnt = 0;
  while(!q.empty()){
    auto from = q.front();
    q.pop();
    sharp_cnt++;

    int xx = from.first;
    int yy = from.second;

    if(xx== H-1 && yy == W - 1){
      break;
    }

    int cnt = 0;

    REP(i, 2){
      int x = xx + d[i];
      int y = yy + d[i^1];

      if(x < 0 || x > H-1 || y < 0 || y > W-1 || grid[x][y] == '.'){
        continue;
      }
      q.push({x,y});
      cnt++;
    }

    if(cnt != 1) break;
  }

  if(sharp_cnt == sharp){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
}

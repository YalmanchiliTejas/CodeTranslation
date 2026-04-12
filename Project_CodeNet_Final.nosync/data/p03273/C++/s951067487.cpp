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
const ll INF = 1e18;
/* テンプレートここまで */

int main() {
  ll H, W; cin >> H >> W;
  vector<string> grid(H);
  vector<bool> tate(H, false);
  vector<bool> yoko(W, false);
  REP(i, H) cin >> grid[i];
  REP(i, H) REP(j, W) {
    if(grid[i][j] == '#'){
      tate[i] = true;
      yoko[j] = true;
    }
  }
  REP(i, H) REP(j, W){
    if(!tate[i]) continue;
    if(yoko[j]) cout << grid[i][j];
    if(j == W-1) cout << endl;
  } 
}     
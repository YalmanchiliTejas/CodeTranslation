#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
int cnt ;
int H,W;
bool flag;
char board[10][10];
void dfs(int i, int j, int dfsCnt){
  if(dfsCnt == cnt){
    flag = true;
  }
  if(i+1 < H && board[i+1][j] == '#'){
    dfs(i+1,j,dfsCnt+1);
  }

  if(j+1 < W && board[i][j+1] == '#'){
    dfs(i,j+1,dfsCnt+1);
  }
  return;
}
int main(){
  cin >> H >> W;

  rep(i,H)rep(j,W){
    cin >> board[i][j];
  }

  rep(i,H)rep(j,W){
    if(board[i][j] == '#') cnt ++;
  }

  dfs(0,0,1);
  if(flag)cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}

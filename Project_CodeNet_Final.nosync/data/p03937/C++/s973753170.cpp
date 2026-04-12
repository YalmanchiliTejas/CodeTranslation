#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int H, W;
char A[10][10];
// #が全部でいくつあるか
int all_cost = 0;

//右か下に移動する
int dy[] = {0, 1};
int dx[] = {1, 0};

bool dfs(int nowy, int nowx, int cost){
  //cout<<nowy+1<<" "<<nowx+1<<" "<<cost<<endl;
  // 通ってきた道が#の数に等しい，かつ右下に到達している
  if(cost == all_cost && nowy==H-1 && nowx==W-1)
    return true;
  
  // 右か下に移動できるならする
  rep(k, 2){
    // 枠からはみ出したらスキップ
    if(nowy+dy[k]>=H || nowx+dx[k]>=W)
      continue;
    
    // 次の道があればそこからDFSを始める
    if(A[nowy + dy[k] ][nowx + dx[k] ] == '#'){
      if( dfs(nowy + dy[k], nowx + dx[k], cost+1) )
	return true;
    }
  }
  // 上でtrueを返さなければ失敗
  return false;
}


int main(){
  cin >> H >> W;
  rep(i, H)
    rep(j, W){
    cin >> A[i][j];
    if(A[i][j] == '#')
      all_cost++;
  }
  // 入力終了

  if( dfs(0, 0, 1) )
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  
  return 0;
}

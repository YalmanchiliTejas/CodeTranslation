#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF=1000000000;

char maze[10][10]; //迷路の文字列
int N, M; 
int sx, sy; //スタートの座標
int gx, gy; //ゴールの座標

int d[10][10]; //各点までの最短距離の配列

//移動の4方向のベクトル
int dx[2] = {1, 0 }, dy[2] = {0, 1 };
int bfs(){
    queue<P> que;
    rep(i, N) rep(j, M) d[i][j] = INF; //全ての点を初期化
    //スタート地点をキューに入れ、その点の距離を0にする
    que.push(P(sx, sy)); 
    d[sx][sy] = 0;

    //キューが空になるまでループ
    while(que.size()){
        //キューの先頭を取り出す(ゴールなら探索終了)
        P p = que.front(); que.pop();
        if(p.first == gx && p.second == gy) break;
        //移動4方向をループ
        rep(i, 2){
            //移動先の点を仮において移動可能か既に訪れたか判定
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '.' && d[nx][ny] == INF){
                que.push(P(nx, ny));
                //移動可能ならキューに入れ、距離を今の地点+1する
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main(){
  cin>>N>>M;
  int count=0;
  rep(i,N) rep(j,M){
      cin>>maze[i][j];
      if(maze[i][j]=='#') count++;
  } 
 sx=0, sy=0; 
 gx=N-1, gy=M-1;
  int ans=bfs();

  if(ans!=count-1) cout<<"Impossible"<<endl;
  else cout<<"Possible"<<endl;




}
#include <bits/stdc++.h>
using namespace std;

const int INF=123456789;

typedef pair<int,int> P;

char maze[101][101];
int H,W;

int d[101][101];

int dx[2]={1,0}, dy[2]={0,1};

//sxsyからgxgyへの最短距離を求める

int bfs(int sy,int sx,int gy,int gx){
  if(maze[sy][sx]=='.' || maze[gy][gx]=='.') return 123456789;
  queue<P> que;
  for(int i=0;i<H;i++) {
    for(int j=0;j<W;j++){
       d[i][j]=INF;
     }
   }
  que.push(P(sy,sx));
  d[sy][sx]=0;

  while(que.size()){
    P p=que.front();que.pop();
    if(p.second==gx&&p.first==gy) break;

    for(int i=0;i<2;i++){
      int nx=p.second+dx[i], ny=p.first+dy[i];
      if(0<=nx&&nx<W&&0<=ny&&ny<H&&maze[ny][nx]!='.'&&d[ny][nx]==INF){
        que.push(P(ny,nx));
        d[ny][nx] = d[p.first][p.second]+1;
      }
    }
  }


  return d[gy][gx];
}

void solve(){

}

int main(){
  cin>>H>>W;
  for(int i=0;i<H;i++) for(int j=0;j<W;j++){
    cin>>maze[i][j];
  }
 int ans = bfs(0,0,H-1,W-1);
 int b[101];

 for(int i=0;i<H*W;i++) b[i]=0;
 for(int i=0;i<H;i++) for(int j=0;j<W;j++){
   if(d[i][j]!=INF)b[d[i][j]-1]++;
   if(d[i][j]==INF&&maze[i][j]=='#'){
     cout<<"Impossible"<<endl;
     return 0;
   }
 }

 for(int i=0;i<H*W;i++){
   if(b[i]>=2){
     cout<<"Impossible"<<endl;
     return 0;
   }
 }
 if(d[H-1][W-1]!=INF)  cout<<"Possible"<<endl;
 else cout<<"Impossible"<<endl;

}

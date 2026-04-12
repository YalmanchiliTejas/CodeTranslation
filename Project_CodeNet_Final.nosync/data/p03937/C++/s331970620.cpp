#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int H,W;
char maze[30][310];
int d[30][30];
int dx[2]={1,0};
int dy[2]={0,1};
void bfs(int sx,int sy){
    queue<pair<int,int>> que;
    rep(i,H){
        rep(j,W){
            d[i][j]=INF;
        }
    }
 
    que.push(make_pair(sx,sy)); // (0,0)ã‚¹ã‚¿ãƒ¼ãƒˆ
    d[sx][sy]=0;
    while(!que.empty()){
        pair<int,int> p=que.front();
        que.pop();
        for(int i=0;i<2;i++){
            int nx=p.first+dx[i];
            int ny=p.second+dy[i];
            if(0<=nx && nx<H && 0<=ny && ny<W && maze[nx][ny]=='#' && d[nx][ny]==INF){
                que.push(make_pair(nx,ny));
                d[nx][ny]=d[p.first][p.second]+1;
                break;
            }
        }
    }
}

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>maze[i][j];
    bfs(0,0);
    rep(i,H){
        rep(j,W){
            if(maze[i][j]=='#' && d[i][j]==INF){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }

    cout<<"Possible"<<endl;
}
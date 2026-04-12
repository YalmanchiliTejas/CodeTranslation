#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
typedef long long ll;
const int N = 100;
char m[N][N];
vector<int> t[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool vis[N][N];
int on[N][N];
int off[N][N];
int keep[N][N];

bool dfs(int r,int c,int y,int x,int ty,int tx,int ti,int &total){
  if (vis[y][x])return false;
  if (y == ty && x == tx){
    
    return true;
  }
  vis[y][x]=true;
  rep(i,4){
    int nex=x+dx[i],ney=y+dy[i];
    if (nex == -1 || ney == -1 || nex == c || ney == r || 
        m[ney][nex] == '#')continue;
    if (dfs(r,c,ney,nex,ty,tx,ti+1,total)){
      total++;
      t[y][x].push_back(ti);
      return true;
    }
  }
  return false;
}

int main(){
  int r,c,q;
  while(cin>>r>>c>>q){
    rep(i,r)rep(j,c)t[i][j].clear();
    rep(i,r)cin>>m[i];
    //bool dfs(int r,int c,int y,int x,int ty,int tx,int ti,int &total);
    rep(i,r)rep(j,c)cin>>keep[i][j];
    rep(i,r)rep(j,c)cin>>on[i][j];
    rep(i,r)rep(j,c)cin>>off[i][j];

    int total=0;
    int py,px;
    rep(i,q){
      rep(ii,r)rep(jj,c)vis[ii][jj]=false;
      int sy,sx;
      cin>>sy>>sx;
      if (i != 0){
        dfs(r,c,py,px,sy,sx,total,total);
      }
      if (i == q-1)t[sy][sx].push_back(total);
      py=sy;
      px=sx;
    }
    ll ans=0;
    rep(i,r){
      rep(j,c){
        if (t[i][j].size() == 0)continue;
        //debqug
        /*
          cout <<"node i j " << i <<" " << j <<" : ";
          rep(k,(int)t[i][j].size()){
          cout << t[i][j][k] << " ";
          }
          cout << endl;
        */
        ans+=on[i][j]+off[i][j];
        REP(k,1,(int)t[i][j].size()){
          ll dif=t[i][j][k]-t[i][j][k-1];
          ll costa=dif*keep[i][j];//keep
          ll costb=on[i][j]+off[i][j];//off->onn
          ans+=min(costa,costb);
        }
      }
    }
    cout << ans << endl;
  }
  return false;
}
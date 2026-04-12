#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define M 1005
#define N 51
using namespace std;
int r,c,m,gy,gx,T,ans;
int C[3][N][N];
bool used[N][N];
string s[N];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int d[N][N];

void update(int y,int x,int t){
  if(d[y][x]==-1)ans+=C[1][y][x]+C[2][y][x];
  else ans+=min((t-d[y][x])*C[0][y][x],
		C[1][y][x]+C[2][y][x]);
  d[y][x]=t;
}

bool dfs(int y,int x,int t){
  
  if(used[y][x])return false;
  used[y][x]=true;
  
  if(y==gy&&x==gx){
    update(y,x,t);
    T=t;
    return true;
  }
  
  bool res=false;
  rep(i,4){
    int ny=y+dy[i],nx=x+dx[i];
    if(ny<0||nx<0||r<=ny||c<=nx)continue;
    if(s[ny][nx]=='#')continue;
    res|=dfs(ny,nx,t+1);
  }
  if(res)update(y,x,t);
  
  return res;
}

int y[M],x[M];

int main(){
  cin>>r>>c>>m;
  rep(i,r)cin>>s[i];
  
  rep(i,3)
    rep(j,r)
      rep(k,c)cin>>C[i][j][k];
  
  rep(i,m)cin>>y[i]>>x[i];
  
  memset(d,-1,sizeof(d));
  
  rep(i,m-1){
    gy=y[i+1],gx=x[i+1];
    memset(used,0,sizeof(used));
    dfs(y[i],x[i],T);
  }
  
  cout<<ans<<endl;
  return 0;
}
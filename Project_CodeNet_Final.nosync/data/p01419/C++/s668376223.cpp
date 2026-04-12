#include<bits/stdc++.h>
using namespace std;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int H,W,M;
int sy,sx;
char t[50][50];
int p[50][50];
int q[50][50];
int a[50][50];
int b[50][50];
int c[50][50];
int g[50][50];

vector<int> calc(int ay,int ax,int by,int bx){
  vector<int> c,d;
  while(ay!=by||ax!=bx){
    if(q[ay][ax]>q[by][bx]){
      int dir=p[ay][ax];
      c.push_back(dir);
      ay+=dy[dir];
      ax+=dx[dir];
    }else{
      int dir=p[by][bx];
      d.push_back(dir);
      by+=dy[dir];
      bx+=dx[dir];
    }
  }
  reverse(d.begin(),d.end());
  for(int i=0;i<(int)d.size();i++)c.push_back((d[i]+2)%4);
  return c;
}

void rec(int y,int x,int z){
  for(int i=0;i<4;i++){
    int ny=y+dy[i],nx=x+dx[i];
    if(ny<0||nx<0)continue;
    if(ny>=H||nx>=W)continue;
    if(t[ny][nx]=='#')continue;
    if(p[ny][nx]==-1){
      p[ny][nx]=(i+2)%4;
      q[ny][nx]=z+1;
      rec(ny,nx,z+1);
    }
  }
}

void init(){
  sy=-1;
  for(int i=0;i<50;i++){
    for(int j=0;j<50;j++){
      p[i][j]=-1;
      g[i][j]=-1;
    }
  }
}

int main(){
  cin>>H>>W>>M;
  init();
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>t[i][j];
      if(t[i][j]=='.'&&sy==-1)sy=i,sx=j;
    }
  }
  
  p[sy][sx]=-2;
  q[sy][sx]=0;
  rec(sy,sx,0);
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>a[i][j];
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>b[i][j];
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>c[i][j];  
  int ay,ax,by,bx,cnt=0,ans=0;
  cin>>by>>bx;
  for(int i=0;i<M-1;i++){
    ay=by;ax=bx;
    cin>>by>>bx;
    vector<int> v=calc(ay,ax,by,bx);
    for(int j=0;j<(int)v.size();j++){
      if(g[ay][ax]==-1){
        ans+=b[ay][ax]+c[ay][ax];
      }else{
        int A=b[ay][ax]+c[ay][ax];
        int d=cnt-g[ay][ax];
        int B=d*a[ay][ax];
        ans+=min(A,B);
      }
      g[ay][ax]=cnt;
      ay+=dy[v[j]];
      ax+=dx[v[j]];
      cnt++;
    }
  }
  if(g[ay][ax]==-1){
    ans+=b[ay][ax]+c[ay][ax];
  }else{
    int A=b[ay][ax]+c[ay][ax];
    int d=cnt-g[ay][ax];
    int B=d*a[ay][ax];
    ans+=min(A,B);
  }
 
  cout<<ans<<endl;

  return 0;
}
  
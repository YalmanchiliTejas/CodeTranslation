//14
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

int nr,nc,m;
char g[50][51];
int ut[50][50];
int on[50][50];
int off[50][50];
int u[50][50];
vector<P> v(1);

bool dfs(P c,P d){
  if(g[c.second][c.first]=='#'||u[c.second][c.first])return false;
  u[c.second][c.first]=1;
  if(c==d)return true;
  for(int i=0;i<4;i++){
    int dr[]={0,-1,0,1,0};
    int nx=c.first+dr[i];
    int ny=c.second+dr[i+1];
    if(ny<0||nr<=ny||nx<0||nc<=nx)continue;
    if(dfs(P(nx,ny),d)){
      v.push_back(c);
      return true;
    }
  }
  u[c.second][c.first]=0;
  return false;
}

int main(){
  cin>>nr>>nc>>m;
  for(int i=0;i<nr;i++){
    cin>>g[i];
  }
  for(int i=0;i<nr;i++){
    for(int j=0;j<nc;j++){
      cin>>ut[i][j];
    }
  }
  for(int i=0;i<nr;i++){
    for(int j=0;j<nc;j++){
      cin>>on[i][j];
    }
  }
  for(int i=0;i<nr;i++){
    for(int j=0;j<nc;j++){
      cin>>off[i][j];
    }
  }
  cin>>v[0].second>>v[0].first;
  for(int i=0;i<m-1;i++){
    P p;
    cin>>p.second>>p.first;
    fill(u[0],u[nr],0);
    dfs(p,v.back());
  }
  bool l[50][50]={};
  int p=0;
  for(int i=0;i<v.size();i++){
    int y=v[i].second;
    int x=v[i].first;
    if(!l[y][x]){
      p+=on[y][x];
    }
    int nx=find(v.begin()+i+1,v.end(),v[i])-v.begin();
    if(nx==v.size()||on[y][x]+off[y][x]<ut[y][x]*(nx-i)){
      p+=off[y][x];
      l[y][x]=false;
    }else{
      p+=ut[y][x]*(nx-i);
      l[y][x]=true;
    }
  }
  cout<<p<<endl;
  return 0;
}
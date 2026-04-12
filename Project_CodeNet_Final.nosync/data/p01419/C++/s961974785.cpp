#include <bits/stdc++.h>
#define N 51
using namespace std;
int h,w,m;
string mp[N];
int c[N*N],on[N*N],off[N*N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

vector<int> path;
int used[N*N];
int dfs(int pos,int t){
  if(pos==t) return 1;
  if(used[pos]++) return 0;
  int x = pos%w,y=pos/w;

  for(int i=0;i<4;i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    int npos = w*ny+nx;
    if(nx<0||ny<0||nx>=w||ny>=h||mp[ny][nx]=='#')continue;
    if(dfs(npos,t)){path.push_back(npos);return 1;}
  }
  return 0;
}

vector<int> job;
int calc(){
  int res=0,sta[N*N]={},cnt=2; 
  res+=on[job[0]];
  sta[job[0]] = 1;
  for(int i=0;i<m-1;i++){
    path.clear();
    memset(used,0,sizeof(used));
    dfs(job[i],job[i+1]);
    for(int j=0;j<path.size();j++){
      int pos = path[path.size()-j-1];
      int &T = sta[pos];
      if(T==0) res+=on[pos];
      else res+=min(on[pos]+off[pos],c[pos]*(cnt-T));
      T=cnt++;
    }
  }
  for(int i=0;i<h*w;i++)if(sta[i])res+=off[i];
  return res;
}

int main(){
  cin>>h>>w>>m;
  for(int i=0;i<h;i++) cin>>mp[i];
  for(int i=0;i<h*w;i++) cin>>c[i];
  for(int i=0;i<h*w;i++) cin>>on[i];
  for(int i=0;i<h*w;i++) cin>>off[i];
  for(int i=0,x,y;i<m;i++)cin>>y>>x,job.push_back(y*w+x);
  cout<<calc()<<endl;
  return 0;
}
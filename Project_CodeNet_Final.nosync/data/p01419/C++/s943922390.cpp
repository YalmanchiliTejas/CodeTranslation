#include<bits/stdc++.h>
using namespace std;
#define int long long
bool in(int y,int x,int h,int w){
  return 0<=y&&y<h&&0<=x&&x<w;
}
signed main(){
  int h,w,m;
  cin>>h>>w>>m;
  string s[h];
  for(int i=0;i<h;i++) cin>>s[i];
  int c[3][h][w];
  for(int k=0;k<3;k++)
    for(int i=0;i<h;i++)
      for(int j=0;j<w;j++)
	cin>>c[k][i][j];
  
  int y[m],x[m];
  for(int i=0;i<m;i++) cin>>y[i]>>x[i];

  vector<int> v[h][w];

  

  int ax[]={1,-1,0,0};
  int ay[]={0,0,1,-1};

  int cd=0;
  for(int k=0;k<m-1;k++){
    int cy=y[k],cx=x[k];
    if(y[k]==y[k+1]&&x[k]==x[k+1]) continue;
    queue<vector<int> > q;
    vector<int> t(1,cy*w+cx);
    q.push(t);
    bool used[h][w];
    memset(used,0,sizeof(used));
    used[cy][cx]=1;
    while(!q.empty()){
      vector<int> p=q.front();q.pop();
      int ty=p[p.size()-1]/w,tx=p[p.size()-1]%w;
      if(ty==y[k+1]&&tx==x[k+1]){
	t=p;
	break;
      }
      for(int i=0;i<4;i++){
	int ny=ty+ay[i],nx=tx+ax[i];
	if(!in(ny,nx,h,w)) continue;
	if(used[ny][nx]||s[ny][nx]=='#') continue;
	used[ny][nx]=1;
	int np=ny*w+nx;
	p.push_back(np);
	q.push(p);
	p.pop_back();
      }
    }
    for(int i=0;i<(int)t.size()-1;i++)
      v[t[i]/w][t[i]%w].push_back(cd++);
    //for(int i=0;i<(int)t.size()-1;i++) cout<<t[i]/w<<" "<<t[i]%w<<endl;
  }
  v[y[m-1]][x[m-1]].push_back(cd);
  int ans=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      //v[i][j].erase(unique(v[i][j].begin(),v[i][j].end()),v[i][j].end());
      ans+=(c[1][i][j]+c[2][i][j])*v[i][j].size();
      
      for(int k=0;k<(int)v[i][j].size()-1;k++){
	if((v[i][j][k+1]-v[i][j][k])*c[0][i][j]<(c[1][i][j]+c[2][i][j]))
	  ans+=(v[i][j][k+1]-v[i][j][k])*c[0][i][j]-(c[1][i][j]+c[2][i][j]);
      }
      
    }
  }
  cout<<ans<<endl;
  return 0;
}
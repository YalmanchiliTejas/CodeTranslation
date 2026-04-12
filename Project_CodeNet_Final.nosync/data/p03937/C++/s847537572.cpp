#include<bits/stdc++.h>
using namespace std;

signed main(){

  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(auto& si:s)cin>>si;

  vector<vector<int>> visited(h,vector<int>(w,0));
  using P = pair<int,int>;
  queue<P> que;
  que.emplace(0,0);
  while(!que.empty()){
    int y,x;
    tie(y,x) = que.front();
    que.pop();
    if(y==h||x==w)continue;
    if(s[y][x]=='.')continue;
    visited[y][x] = 1;
    if(x+1<w&&s[y][x+1]=='#')que.emplace(y,x+1);
    else que.emplace(y+1,x);
  }
  bool ok = true;
  for(int i=0;i<h;++i)for(int j=0;j<w;++j){
    if(s[i][j]=='#'){
      if(visited[i][j]==0)ok=false;
    }
  }
  cout<<(ok?"Possible":"Impossible")<<endl;

}
#include <bits/stdc++.h>  
using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)
using graph = vector<vector<char>>;

graph g;
void h_(int i,int w){
  rep(j,w){
    if(g[i][j]=='#'){return;}
  }
  rep(j,w){g[i][j]='n';}
  return;
}
void w_(int j,int h){
  rep(i,h){
    if(g[i][j]=='#'){return;}
  }
  rep(i,h){g[i][j]='n';}
  return;
}
int main(){
  int h,w; cin>>h>>w;
  g.assign(h,vector<char>(w));
  rep(i,h){
    rep(j,w){cin>>g[i][j];}
  }
  int i=0;
  rep(i,h){ h_(i,w);}  
  rep(j,w){ w_(j,h);}
  rep(i,h){
    int c=count(g[i].begin(),g[i].end(),'#');
    rep(j,w){
      if(g[i][j]!='n')cout<<g[i][j];
      if(j==w-1&&c>0){cout<<endl;}
    }
  }
}


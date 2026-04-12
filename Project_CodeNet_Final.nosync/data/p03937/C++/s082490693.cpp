#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int h,w;
char grid[10][10];
bool ok;
bool seen[10][10];

void dfs(int y, int x){
  if(y==h-1 && x==w-1){
    ok=1;
  }
  if(grid[y][x]!='#')return;
  if(grid[y+1][x]=='#' && grid[y][x+1]=='#')return;
  seen[y][x]=1;
  dfs(y+1,x);
  dfs(y,x+1);
  return;
}

int main(){
  cin>>h>>w;
  rep(i,h)rep(j,w){
    cin>>grid[i][j];
    seen[i][j]=0;
  }
  ok=0;
  dfs(0,0);
  if(ok){
    bool all=1;
    rep(i,h)rep(j,w){
      if(grid[i][j]=='#'){
        if(seen[i][j]==0) all=0;
      }
    }
    if(all)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
  } 
  else cout<<"Impossible"<<endl;
}


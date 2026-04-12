#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=12;
char s[mx][mx];
bool vis[mx][mx];
int dir[2][2]={{1,0},{0,1}};
int n,m;
void dfs(int r,int c){
  vis[r][c]=true;
  for(int i=0;i<2;i++){
    int nr=r+dir[i][0];
    int nc=c+dir[i][1];
    if(0<=nr && nr<n && 0<=nc && nc<m && !vis[nr][nc] && s[nr][nc]=='#'){
      dfs(nr,nc);
      break;
    }
  }
}
int main(){
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%s",s[i]);
  }
  dfs(0,0);
  bool ok=true;
  for(int i=0;i<n;i++)for(int j=0;j<m;j++){
    if(s[i][j]=='#' && !vis[i][j])ok=false;
  }
  if(ok)puts("Possible");
  else puts("Impossible");
  return 0;
}

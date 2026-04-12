// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll h,w;
string s[10];
bool d[10][10];
ll dfs(ll x,ll y){
  d[x][y] = true;
  ll res=0;
  ll dx[]={1,0,-1,0},dy[]={0,1,0,-1},nx,ny;
  for(int i=0;i<4;i++){
    nx = dx[i]+x;
    ny = dy[i]+y;
    if(nx>=0 && ny>=0 && nx<h && ny<w && s[nx][ny]=='#'&&!d[nx][ny]){
      res+=dfs(nx,ny);
    }
  }
  return res+1;
}
signed main(){
  ll v;
  cin >> h >> w;
  fill(d[0],d[10],false);
  for(int i=0;i<h;i++){
    cin >> s[i];
  }
  v = dfs(0,0);
  if(v==h+w-1){
    cout <<"Possible\n";
  }else{
    cout <<"Impossible\n";
  }
}

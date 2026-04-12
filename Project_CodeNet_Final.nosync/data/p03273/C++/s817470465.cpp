///スマホコーディング
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
typedef long long ll;
const int inf=1e9;
int main(){
  int h,w;cin>>h>>w;
  vector<vector<char>> f(h,vector<char>(w));  
  vector<vector<bool>> t(h,vector<bool>(w,true));
  rep(i,h)rep(j,w)cin>>f[i][j];
  //rep(i,h)rep(j,w)cout<<f[i][j];
  rep(i,h){
    int cnt=0;
    rep(j,w)if(f[i][j]=='.')cnt++;
    if(cnt==w)rep(j,w)t[i][j]=false;
  }
  rep(j,w){
    int cnt=0;
    rep(i,h)if(f[i][j]=='.')cnt++;
    if(cnt==h)rep(i,h)t[i][j]=false;
  }
  rep(i,h){
    bool flag=false;
    rep(j,w)if(t[i][j]){
      cout<<f[i][j];
      flag=true;
    }
    if(flag)cout<<endl;
  }
  return 0;
}
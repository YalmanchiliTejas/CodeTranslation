#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h)rep(j,w)cin>>a[i][j];
  vector<bool> t(h),y(w);
  rep(i,h){
    rep(j,w){
      if(a[i][j]=='#')t[i]=y[j]=true;
    }
  }
  rep(i,h){
    if(t[i]){
      rep(j,w){
        if(y[j])cout<<a[i][j];
        if(j==w-1)cout<<endl;
      }
    }
  }
}

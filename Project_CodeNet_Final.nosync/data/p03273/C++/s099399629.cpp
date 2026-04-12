#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int h,w;cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h)rep(j,w)cin>>a[i][j];
  vector<bool> b(h),c(w);
  rep(i,h)rep(j,w){
    if(a[i][j]=='#')b[i]=c[j]=true;
  }
  rep(i,h){
    if(b[i]){
      rep(j,w){
        if(c[j])cout<<a[i][j];
          if(j==w-1)cout<<endl;
      }
    }
  }
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
int main() {
  int h,w;
  cin>>h; cin>>w;
  vector<string> a(h);
  rep(i,h) cin>>a[i];
  vector<bool> height(h),width(w);
  rep(i,h){
    rep(j,w){
      if(a[i][j]=='#'){
        height[i]=true;
        width[j]=true;
      }
    }
  }
  rep(i,h){
    if(height[i]){
      rep(j,w) if(width[j]) cout<<a[i][j];
      cout<<endl;
    }
  }
}
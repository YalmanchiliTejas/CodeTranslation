#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
  int h,w,cnt=0;
  bool dots=false;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  vector<int> hh(0);
  vector<int> ww(0);
  rep(i,h)rep(j,w) cin >> a[i][j];
  rep(i,h){
    cnt=0;
    rep(j,w){
      if(a[i][j]=='.') cnt++; 
    }
    if(cnt==w) hh.push_back(i);
  }
  rep(j,w){
    cnt=0;
    rep(i,h){
      if(a[i][j]=='.') cnt++;
    }
    if(cnt==h) ww.push_back(j);
  }
  rep(i,h){
    if(find(hh.begin(), hh.end(),i)==hh.end()){
      rep(j,w){
        if(find(ww.begin(), ww.end(),j)==ww.end()){
          cout << a[i][j];
        }
      }
      cout << "\n";
    }
  }
  
}  
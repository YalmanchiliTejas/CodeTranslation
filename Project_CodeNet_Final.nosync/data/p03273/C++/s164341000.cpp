#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int h,w;
  cin >> h >> w;
  char s[h][w];
  rep(i,h){
    rep(j,w){
      cin >> s[i][j];
    }
  }
  vector<bool> h_is(h),w_is(w);
  rep(i,h){
    rep(j,w){
      if(s[i][j]=='#'){
        h_is.at(i)=true;
        w_is.at(j)=true;
      }
    }
  }
  rep(i,h){
    if(h_is.at(i)){
      rep(j,w){
        if(w_is.at(j)){
          cout << s[i][j];
        }
      }
      cout <<endl;
    }
  }
}
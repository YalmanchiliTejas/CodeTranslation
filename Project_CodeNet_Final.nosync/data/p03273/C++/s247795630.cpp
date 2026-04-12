#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int h,w;
  cin >> h >> w;
  char c[h][w];
  rep(i,h){
    rep(j,w){
      cin >> c[i][j];
    }
  }
  vector<bool> is(h,false),no(w,false);
  rep(i,h){
    rep(j,w){
      if(c[i][j]=='#'){
        is.at(i)=true;
      }
    }
  }
  rep(i,w){
    rep(j,h){
      if(c[j][i]=='#'){
        no.at(i)=true;
      }
    }
  }
  rep(i,h){
    if(is.at(i)){
      rep(j,w){
        if(no.at(j)){
          cout << c[i][j];
        }
      }
      cout << endl;
    }
  }
}
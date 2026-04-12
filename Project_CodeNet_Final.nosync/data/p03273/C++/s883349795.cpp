#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int h,w; cin >>h >>w;
  string a[h];
  rep(i,h) cin >>a[i];
  vector<bool> x(h, false);
  vector<bool> y(w, false);
  rep(i,h){
    rep(j,w){
      if(a[i][j]=='#'){
        x[i] = true;
        y[j] = true;
      }
    }
  }
  rep(i,h){
    if(x[i]==true){
      rep(j,w){
        if(y[j]==true) cout <<a[i][j];
      }
      cout << endl;
    }
  }
  return 0; 
}
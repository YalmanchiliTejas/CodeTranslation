#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repa(i, a, n) for (int i = (int)(a); i < (int)(n); i++)
#define PI (acos(-1))
#define _GLIBCXX_DEBUG

int main(){
  
  int h, w;
  cin >> h >> w;

  vector<vector<char>> v(h, vector<char>(w));

  rep(i, h){
    rep(j, w){
      cin >> v[i][j];
    }
  }

  vector<bool> y(h, false);
  vector<bool> x(w, false);

  rep(i, h){
    rep(j, w){
      if(v[i][j] == '#'){
        y[j] = true;
        x[i] = true;
      }
    }
  }

  rep(i, h){
    if(x[i]){
      rep(j, w){
        if(y[j]) cout << v[i][j];
        if(j == w-1) cout << endl;
      }
    }
  }

}
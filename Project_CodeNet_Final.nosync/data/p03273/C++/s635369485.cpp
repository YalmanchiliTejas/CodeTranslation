#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int(i)=0;i<(n);i++)

int main() {
  int h, w;
  char t;
  cin >> h >> w;
  vector<vector<bool>> a(h+1, vector<bool>(w+1, 0));
  rep(i,h){
    int s=0;
    rep(j,w+1){
      if(j<w){
        cin >> t;
        if(t == '#'){
          a.at(i).at(j) = 1;
          s++;
        }
      }else a.at(i).at(j) = s;
    }
  }
  rep(j,w){
    int s=0;
    rep(i,h) s += a.at(i).at(j);
    a.at(h).at(j) = s;
  }
  
  rep(i,h){
    if(a.at(i).at(w)) rep(j,w){
      if(a.at(h).at(j)){
        if(a.at(i).at(j)) cout << '#';
        else cout << '.';
      }
      if(j == w-1) cout << endl;
    }
  }
}
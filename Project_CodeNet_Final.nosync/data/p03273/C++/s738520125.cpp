#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int(i)=0;i<(n);i++)

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  vector<bool> hh(h,0), ww(w,0);
  rep(i,h) rep(j,w){
    cin >> a.at(i).at(j);
    if(a.at(i).at(j) == '#'){
      hh.at(i) = 1;
      ww.at(j) = 1;
    }    
  }
  rep(i,h){
    rep(j,w) if(hh.at(i) && ww.at(j)){
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int h,w;
  cin >> h >> w;

  vector<vector<char>> grid(h, vector<char>(w));
  rep(i,h)rep(j,w) cin >> grid.at(i).at(j);

  vector<int> h_check(h,0);
  vector<int> w_check(w,0);
  rep(i,h){
    bool check=true;
    rep(j,w){
      if(grid.at(i).at(j)=='#'){check=false; break;}
    }
    if(check) h_check.at(i)=1;
  }

  rep(j,w){
    bool check=true;
    rep(i,h){
      if(grid.at(i).at(j)=='#'){check=false; break;}
    }
    if(check) w_check.at(j)=1;
  }

  rep(i,h){
    rep(j,w){
      if(h_check.at(i)||w_check.at(j)) continue;
      cout << grid.at(i).at(j);
    }
    if(!h_check.at(i)) cout << endl;
  }
}
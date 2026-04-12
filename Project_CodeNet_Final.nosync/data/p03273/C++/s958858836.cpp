#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i > 0; i++)

using ll=long long;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<string> vec(h);
  rep(i,h) cin >> vec[i];
  vector<bool> J(h,1);
  rep(i,h) {
    bool X=1;
    rep(j,w) {
      if(vec[i][j]=='#') X=0;
    }
    if(X) {vec[i] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    J[i] = 0;}
  }
  
  rep(i,w) {
    bool Y =1;
    rep(j,h) {
      if(vec[j][i]=='#') Y=0;
    }
    if(Y) rep(j,h)vec[j][i] = '0';
  }
    
  rep(i,h){
    rep(j,w) {
      if(vec[i][j]=='0') {
        continue;
      }
      cout<<vec[i][j];
    }
    if(J[i])cout<<endl;
  }
}

#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a.at(i);
  vector<bool> bh(h, false), bw(w, false);
  rep(i, h)rep(j, w){
    if(a.at(i).at(j) == '#'){
      bh.at(i) = true;
      bw.at(j) = true;
    }
  }
  rep(i, h){
    if(bh.at(i) == false) continue;
    rep(j, w){
      if(bw.at(j) == false) continue;
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
  return 0;
}
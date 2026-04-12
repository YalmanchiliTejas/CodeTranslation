#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(snip_i, h) cin >> a.at(snip_i);
  int co = 0;
  rep(i, h){
    rep(j, w){
      if(a.at(i).at(j) == '#') co++;
    }
  }
  if(co == h+w-1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}
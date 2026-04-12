#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h)cin >> s[i];
  vector<vector<bool>> is(h,vector<bool>(w,1));
  rep(i,h){
    bool ok = true;
    rep(j,w)if(s[i][j] == '#')ok = false;
    if(ok)rep(j,w)is[i][j] = false;
  }
  rep(i,w){
    bool ok = true;
    rep(j,h)if(s[j][i] == '#')ok = false;
    if(ok)rep(j,h)is[j][i] = false;
  }
  rep(i,h){
    bool ok = false;
    rep(j,w)if(is[i][j])cout << s[i][j],ok = true;
    if(ok)cout << endl;
  }






  

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

int main(){
  int h,w; cin >> h >> w;

  vector<string> g(h);
  rep(i,h) cin >> g[i];

  vector<bool> hh(h,false), ww(w,false);

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(g[i][j] == '#'){
        hh[i] = true;
        ww[j] = true;
      }
    }
  }

  for(int i = 0; i < h; i++){
    if(!hh[i]) continue;
    for(int j = 0; j < w; j++){
      if(!ww[j]) continue;
      cout << g[i][j];
    }
    cout << endl;
  }
  return 0;
}

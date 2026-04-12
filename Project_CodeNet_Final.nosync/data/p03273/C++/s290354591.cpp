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
  vector<bool> ch(h,false), cw(w,false);

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(g[i][j] == '#') break;
      if(j+1 == w) ch[i] = true;
    }
  }
  for(int i = 0; i < w; i++){
    for(int j = 0; j < h; j++){
      if(g[j][i] == '#') break;
      if(j+1 == h) cw[i] = true;
    }
  }
  for(int i = 0; i < h; i++){
    if(ch[i]) continue;
    for(int j = 0; j < w; j++){
      if(cw[j]) continue;
      cout << g[i][j];
    }
    cout << endl;
  }
  return 0;
}

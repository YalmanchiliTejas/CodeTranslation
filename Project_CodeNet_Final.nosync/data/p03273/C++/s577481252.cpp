#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
using vi = vector<int>;
using vll = vector<ll>;
const ll INF = 1LL<<60;

int main(){
  int h,w;
  cin >> h >> w;

  vector<string> g(h);

  for(int i = 0; i < h; i++) cin >> g[i];

  vector<int> r(h,0), c(w,0);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(g[i][j] == '#'){
        r[i] = 1;
        c[j] = 1;
      }
    }
  }
  for(int i = 0; i < h; i++){
    if(!r[i]) continue;
    for(int j = 0; j < w; j++){
      if(!c[j]) continue;
      cout << g[i][j];
    }
    cout << endl;
  }
  return 0;
}

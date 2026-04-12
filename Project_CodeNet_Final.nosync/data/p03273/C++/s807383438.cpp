#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
typedef long long ll;
const int inf = 100100100;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> g(h);
  rep(i,h) cin >> g[i];

  vector<int> H(0), W(0);

  rep(i,h){
    bool flag = 0;
    rep(j,w) if(g[i][j] == '#') flag = 1;
    if(flag)H.push_back(i);
  }
  rep(j,w){
    bool flag = 0;
    rep(i,h) if(g[i][j] == '#') flag = 1;
    if(flag) W.push_back(j);
  }
  for(auto i : H){
    for(auto j : W){
      cout << g[i][j];
    }
    cout << endl;
  }
}


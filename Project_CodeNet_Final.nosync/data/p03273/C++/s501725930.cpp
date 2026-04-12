#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  vector<int> h(H);
  vector<int> w(W);
  rep(i,H){
    rep(j,W){
      cin >> a.at(i).at(j);
      if(a.at(i).at(j) == '#'){
        h.at(i) = 1;
        w.at(j) = 1;
      }
    }
  }
  rep(i,H){
    if(h.at(i) == 1){
      rep(j,W){
        if(w.at(j) == 1){
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
  return 0;
}
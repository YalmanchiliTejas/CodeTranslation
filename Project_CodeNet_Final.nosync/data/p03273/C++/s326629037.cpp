#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, 0, h) {
    rep(j, 0, w) {
      cin >> a.at(i).at(j);
    }
  }
  vector<bool> hh(h, false);
  vector<bool> ww(w, false);
  
  rep(i, 0, h) {
    rep(j, 0, w) {
      if(a.at(i).at(j) == '#') {
        hh.at(i) = true;
        ww.at(j) = true;
      }        
    }
  }
  
  rep(i, 0, h) {
    if(hh.at(i)) {
      rep(j, 0, w) {
        if(ww.at(j))
          cout << a.at(i).at(j);
      }
      cout << "\n";
    }
  }

}

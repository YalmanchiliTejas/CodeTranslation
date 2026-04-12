#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define chmin(x,y) x=min(x,y)
using namespace std;
using P = pair<int,int>;

const int INF = 1001001001;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> matrix(h,vector<char>(w));
  rep(i,h) rep(j,w) cin >> matrix.at(i).at(j);
    
  vector<vector<char>> ans(h,vector<char>(w));
  vector<vector<char>> ans1(h,vector<char>(w));
  
  int ans_h = 0;
  int ans_w = 0;
  rep(i,h) {
    bool judge = true;
    rep(j,w) if(matrix.at(i).at(j) == '#') judge = false;
    if(!judge) {
      rep(j,w) ans.at(ans_h).at(j) = matrix.at(i).at(j);
      ans_h++;
    }
  }
   rep(j,w) {
    bool judge = true;
    rep(i,h) if(ans.at(i).at(j) == '#') judge = false;
    if(!judge) {
      rep(i,h) ans1.at(i).at(ans_w) = ans.at(i).at(j);
      ans_w++;
    }
  }
  rep(i,ans_h) {
    rep(j,ans_w) cout << ans1.at(i).at(j);
    cout << endl;
  }
      
}

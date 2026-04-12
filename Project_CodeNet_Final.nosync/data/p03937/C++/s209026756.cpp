#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  rep(i, H) rep(j, W) cin >> A[i][j];
  vector<vector<char>> res(H, vector<char>(W, '.'));
  int x = 0, y = 0;
  res[x][y] = '#';
  while(x != H-1 || y != W-1) {
    bool d=false, r=false;
    if(x < H-1 && A[x+1][y] == '#')
      d = true;
    if(y < W-1 && A[x][y+1] == '#')
      r = true;
    if(!d && r) {
      y++;
      res[x][y] = '#';
    }
    else if(d && !r) {
      x++;
      res[x][y] = '#';
    } else {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  rep(i, H) rep(j, W) {
    if(res[i][j] != A[i][j]) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
  return 0;
}
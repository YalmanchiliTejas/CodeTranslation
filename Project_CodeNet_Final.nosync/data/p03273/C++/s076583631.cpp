#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  int H, W; cin >> H >> W;
  vector<bool> out_x(W, false);
  vector<bool> out_y(H, false);
  vector<string> A(H); rep(i,H) cin >> A[i];
  rep(y,H) {
    int whitecount = 0;
    rep(x,W){
      if(A[y][x] == '.') whitecount++;
    }
    if(whitecount == W){
      out_y[y] = true;
    }
  }
  rep(x,W){
    int whitecount = 0;
    rep(y,H){
      if(A[y][x] == '.') whitecount++;
    }
    if(whitecount == H){
      out_x[x] = true;
    }
  }
  rep(i,H){
    if(out_y[i]) continue;
    rep(j,W){
      if(out_x[j]) continue;
      cout << A[i][j];
    }
    cout << endl;
  }
  return 0;
}

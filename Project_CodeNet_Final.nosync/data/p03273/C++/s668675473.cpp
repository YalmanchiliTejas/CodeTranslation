#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
int H, W;
char A[100][100];
vector<int> remove_hs, remove_ws; // 消す行と列
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  rep(i, H) rep(j, W) cin >> A[i][j];
  
  // 縦の操作
  int cnt;
  rep(i, H) {
    cnt = 0;
    rep(j, W) {
      if (A[i][j] == '.') cnt++;
      else break; 
    }
    if (cnt == W) remove_hs.push_back(i);
  }
  // 横の操作
  rep(i, W) {
    cnt = 0;
    rep(j, H) {
      if (A[j][i] == '.') cnt++;
      else break; 
    }
    if (cnt == H) remove_ws.push_back(i);
  }
  int h_idx = 0;
  int w_idx = 0;
  rep(i, H) {
    if (remove_hs.size() > 0 && i == remove_hs[h_idx]) {
      h_idx++;
      continue;
    }
    rep(j, W) {
      if (remove_ws.size() > 0 && j == remove_ws[w_idx]) {
        w_idx++;
        continue;
      }
      cout << A[i][j];
    }
    w_idx = 0;
    cout << "\n";
  }
  return 0;
}
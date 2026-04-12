#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  char a[110][110];
  
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> a[i][j];
    } 
  }
  
  
  vector<bool> row(110, false), column(110, false);
  
  // が全部白の行を見つける
  bool cond = true;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (a[i][j] == '#') break;
      if (j == W) column[i] = true;
    }
  }
  
  // 全部が白の列を見つける
  for (int j = 1; j <= W; j++) {
    for (int i = 1; i <= H; i++) {
      if (a[i][j] == '#') break;
      
      if(i == H) row[j] = true;
    }
  }

  
  
  for (int i = 1; i <= H; i++) {
    if (column[i]) continue;
    for (int j = 1; j <= W; j++) {
      if (row[j]) continue;
      
      cout << a[i][j];
    }
    cout<< endl;
  }
}
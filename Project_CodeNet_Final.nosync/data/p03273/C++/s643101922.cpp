#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cout.setf(ios::fixed); cout.precision(17);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> grid(h, vector<int>(w));
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      char x;
      cin >> x;
      if(x == '#') grid[i][j] = 1;
      else grid[i][j] = 0;
    }
  }
  vector<int> row(h, 0);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      row[i] += grid[i][j];
    }
  }
  vector<int> col(w, 0);
  for(int j = 0; j < w; j++){
    for(int i = 0; i < h; i++){
      col[j] += grid[i][j];
    }
  }
  for(int i = 0; i < h; i++){
    bool space = false;
    for(int j = 0; j < w; j++){
      if(!row[i] || !col[j]) continue;
      cout << (grid[i][j] ? '#' : '.');
      space = true;
    }
    if(space) cout << "\n";
  }
  return 0;
}


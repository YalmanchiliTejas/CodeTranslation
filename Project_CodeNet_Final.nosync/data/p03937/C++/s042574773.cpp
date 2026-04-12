#include <bits/stdc++.h>
using namespace std;
int main(){
  int h, w, cnt = 0;
  cin >> h >> w;
  vector<vector<char>> a(h+1, vector<char>(w+1, 'z'));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#') cnt++;
      if (cnt > h+w-1) {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i == h-1 && j == w-1) continue;
      if (a[i][j] == '#' && a[i+1][j] != '#' && a[i][j+1] != '#') {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  
  cout << "Possible" << endl;
}
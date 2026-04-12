#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h, w;
  cin >> h >> w;
  
  vector<vector<char>> map (h,vector<char>(w));
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> map.at(i).at(j);
    }
  }
  
  vector<bool> line(h,false);
  vector<bool> column(w,false);
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++){
      if (map.at(i).at(j) == '#') {
        line.at(i) = true;
        column.at(j) = true;
      }
    }
  }
  
  for(int i = 0; i < h; i++) {
    if (line.at(i)) {
      for (int j = 0; j < w; j++) {
        if(column.at(j)) {
          cout << map.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, i, j, k, x = 0, y = 0;
  cin >> h >> w;
  
  vector<vector<char>> a(h, vector<char>(w)), b(h, vector<char>(w)), c(h, vector<char>(w));
  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      if(a.at(i).at(j) == '#'){
        for(k = 0; k < w; k++){
          b.at(x).at(k) = a.at(i).at(k);
        }
        x++;
        break;
      }
    }
  }
  
  for(i = 0; i < w; i++){
    for(j = 0; j < x; j++){
      if(b.at(j).at(i) == '#'){
        for(k = 0; k < x; k++){
          c.at(k).at(y) = b.at(k).at(i);
        }
        y++;
        break;
      }
    }
  }
  
  for(i = 0; i < x; i++){
    for(j = 0; j < y; j++){
      cout << c.at(i).at(j);
    }
    cout << endl;
  }
}
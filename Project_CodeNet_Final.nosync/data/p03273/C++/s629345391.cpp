#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int h, w, row, column;
  cin >> h >> w;
  vector<vector<char>> map(h, vector<char>(w));

  for(row = 0; row < h; row++){
    for(column = 0; column < w; column++){
      cin >> map[row][column];
    }
  }

  for(row = 0; row < h; row++){
    for(column = 0; column < w; column++){
      if(map[row][column] == '#') break;
    }
    if(column == w){
      map.erase(map.begin() + row);
      row--;
      h--;
    }
  }

  for(column = 0; column < w; column++){
    for(row = 0; row < h; row++){
      if(map[row][column] == '#') break;
    }
    if(row == h){
      for(row = 0; row < h; row++){
        map[row].erase(map[row].begin() + column);
      }
      column--;
      w--;
    }
  }

  for(row = 0; row < h; row++){
    for(column = 0; column < w; column++){
      cout << map[row][column];
    }
    cout << endl;
  }
  return 0;
}

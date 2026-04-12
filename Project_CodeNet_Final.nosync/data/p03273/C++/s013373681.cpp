#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
  int h = 0, w = 0;
  cin >> h >> w;

  vector<int> col(w, 0);
  vector<string> grid(h, "");
  
  for (int i = 0; i < h; i++) {
    cin >> grid.at(i);
    if (grid.at(i).find('#') == string::npos) {
      grid.at(i) = "";
      continue;
    }
    for (int j = 0; j < w; j++) {
      if (grid.at(i).at(j) == '#') col.at(j)++;
    }
  }
  
  for (int i = 0; i < h; i++) {
    if(grid.at(i).empty()) continue;
    for(int j = 0; j < w; j++) {
      if (col.at(j) == 0) grid.at(i).at(j) = ' ';
    }
    grid.at(i).erase(remove(grid.at(i).begin(),
                            grid.at(i).end(), ' '),
                     grid.at(i).end());
    grid.at(i).push_back('\n');
  }

  for (int i = 0; i < h; i++) {
    cout << grid.at(i);
  }

  return 0;
}
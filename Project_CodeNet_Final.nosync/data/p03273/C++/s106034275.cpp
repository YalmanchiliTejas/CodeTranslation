#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  for (int i=0; i<h; i++) {
    cin >> grid.at(i);
  }
  
  vector<bool> usableRow(h, true);
  vector<bool> usableCol(w, true);
  
  for (int i=0; i<h; i++) {
    bool usable = false;
    for (int j=0; j<w; j++) {
      if (grid.at(i).at(j) == '#') {
        usable = true;
      }
    }
    if (!usable) {
      usableRow.at(i) = false;
    }
  }
  for (int i=0; i<w; i++) {
    bool usable = false;
    for (int j=0; j<h; j++) {
      if (grid.at(j).at(i) == '#') {
        usable = true;
      }
    }
    if (!usable) {
      usableCol.at(i) = false;
    }
  }
  
  for (int i=0; i<h; i++) {
    if (usableRow.at(i)) {
      for (int j=0; j<w; j++) {
        if (usableCol.at(j)) {
          cout << grid.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
  
  
  return 0;
        
}

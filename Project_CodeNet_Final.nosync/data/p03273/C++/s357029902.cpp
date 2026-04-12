#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  vector<string> table(h);
  for (int i = 0; i < h; i++) {
    cin >> table.at(i);
  }
  
  vector<bool> row(h, false);
  vector<bool> column(w, false);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (table.at(i).at(j) == '#') {
        row.at(i) = true;
        column.at(j) = true;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    if (row.at(i)) {
      for (int j = 0; j < w; j++) {
        if (column.at(j)) cout << table.at(i).at(j);
      }
      cout << endl;
    }
  }
}
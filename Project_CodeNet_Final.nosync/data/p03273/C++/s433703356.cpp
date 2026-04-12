#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char> >  itbl(h, vector<char>(w));
  vector<bool> outputRows(h, false);
  vector<bool> outputCols(w, false);
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> itbl.at(i).at(j);
      if(itbl.at(i).at(j) == '#') {
	outputRows.at(i) = true;
	outputCols.at(j) = true;
      }
    }
  }

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(outputRows.at(i) && outputCols.at(j)) {
	cout << itbl.at(i).at(j);
      }
    }
    if(outputRows.at(i)) {
      cout << "\n";
    }
  }
  return 0;
}

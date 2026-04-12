#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char> > a(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a.at(i).at(j);
    }
  }
  for (int i = h-1; i >= 0; i--) {
    if (a.at(i) == vector<char>(w, '.')) {
      a.erase(a.begin() + i);
    }
  }
  bool emptyColumn = true;
  for (int i = w-1; i >= 0; i--) {
    for (int j = 0; j < a.size(); j++) {
      if (a.at(j).at(i) == '#') {
        emptyColumn = false;
        break;
      }
    }
    if (emptyColumn) {
      for (int j = 0; j < a.size(); j++) {
        a.at(j).erase(a.at(j).begin() + i);
      }
    }
    emptyColumn = true;
  }

  h = a.size();
  w = a.at(0).size();

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << a.at(i).at(j);
      if (j == w-1) {
        cout << endl;
      }
    }
  }
}
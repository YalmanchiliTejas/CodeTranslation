#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++)
      cin >> a.at(i).at(j);
  }
  vector<int> H(h, 0), W(w, 0);
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a.at(i).at(j) == '#')
        break;
      if (j == w - 1)
        H.at(i) = 1;
    }
  }
  
  for (int j = 0; j < w; j++) {
    for (int i = 0; i < h; i++) {
      if (a.at(i).at(j) == '#')
        break;
      if (i == h - 1)
        W.at(j) = 1;
    }
  }
  
  for (int i = 0; i < h; i++) {
    if (H.at(i) == 0) {
      for (int j = 0; j < w; j++) {
        if (W.at(j) == 0)
          cout << a.at(i).at(j);
      }
      cout << endl;
    }
  }
  cout << endl;
}


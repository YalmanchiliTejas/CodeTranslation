#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  
  vector<vector<char>> pict(h,vector<char>(w));
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cin >> pict.at(i).at(j);
    }
  }
  
  for (int i=0; i<h; i++) {
    bool sharp = false;
    for (int j=0; j<w; j++) {
      if (pict.at(i).at(j)=='#') {
        sharp = true;
      }
    }
    if (!sharp) {
      pict.at(i) = vector<char>(w,'0');
    }
  }
  
  for (int j=0; j<w; j++) {
    bool sharp = false;
    for (int i=0; i<h; i++) {
      if (pict.at(i).at(j)=='#') {
        sharp = true;
      }
    }
    if (!sharp) {
      for (int k=0; k<h; k++) {
        pict.at(k).at(j) = '0';
      }
    }
  }
  
  for (int i=0; i<h; i++) {
    bool output = false;
    for (int j=0; j<w; j++) {
      if (pict.at(i).at(j) != '0') {
        cout << pict.at(i).at(j);
        output = true;
      }
    }
    if (output) {
      cout << endl;
    }
  }
}
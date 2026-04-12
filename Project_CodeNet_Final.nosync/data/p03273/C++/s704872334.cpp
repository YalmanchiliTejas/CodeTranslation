#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  vector<vector<char>> a(h, vector<char>(w));
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cin >> a.at(i).at(j);
    }
  }
  
  vector<int> tate(h, 0);
  vector<int> yoko(w, 0);
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (a.at(i).at(j) == '#') {
        tate.at(i)=1;
        yoko.at(j)=1;
      }
    }
  }
  
  for (int i=0; i<h; i++) {
    int e=0;
    for (int j=0; j<w; j++) {
      if (min(tate.at(i), yoko.at(j))) {
        cout << a.at(i).at(j);
        e=1;
      }      
    }
    if (e)
      cout << endl;
  }
}
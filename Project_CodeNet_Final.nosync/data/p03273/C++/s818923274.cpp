#include <bits/stdc++.h>
using namespace std;

int main() {
  int h=0, w=0;
  cin >> h >> w;
  
  char a;
  
  vector<vector<char>> vec(h, vector<char>(w));
  vector<vector<char>> vecre(w, vector<char>(h));
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cin >> a;
      vec.at(i).at(j) = a;
      vecre.at(j).at(i) = a;
    }
  }
  
  vector<bool> bvec(h, true);
  vector<bool> bvecre(w, true);
  vector<char> vecch(w, '.');
  vector<char> vecchre(h, '.');
  
  for (int i=0; i<h; i++) {
    if (vecch == vec.at(i)) bvec.at(i) = false;
  }
  
  for (int i=0; i<w; i++) {
    if (vecchre == vecre.at(i)) bvecre.at(i) = false;
  }
  
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (bvec.at(i)) {
        if (bvecre.at(j)) {
          cout << vec.at(i).at(j);
        }
        if (j == w-1) cout << endl;
        else cout << "";
      } else {
        break;
      }
    }
  }
  
}
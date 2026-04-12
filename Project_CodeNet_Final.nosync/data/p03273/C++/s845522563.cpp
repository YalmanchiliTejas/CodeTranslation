#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >>h>>w;
  
  vector<vector<char>> a(h, vector<char>(w));
  
  for (int i=0; i<h; ++i){
    for (int j=0; j<w; ++j){
      cin >> a.at(i).at(j);
    }
  }
  
  vector<bool> yokonoiro(h, false);
  vector<bool> tatenoiro(w, false);
  
  for (int i=0; i<h; ++i){
    for (int j=0; j<w; ++j){
      if (a.at(i).at(j) == '#') {
        yokonoiro.at(i) = true;
        tatenoiro.at(j) = true;
      }
    }
  }
  
  for (int i=0; i<h; ++i){
    if (yokonoiro.at(i)) {
      for (int j=0; j<w; ++j){
        if (tatenoiro.at(j)) {
          cout << a.at(i).at(j) ;
        }
      }
      cout << endl;
    }
  }
}
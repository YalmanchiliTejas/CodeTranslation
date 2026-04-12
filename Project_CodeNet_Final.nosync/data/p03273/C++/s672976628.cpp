#include<bits/stdc++.h>
using namespace std;

bool del(vector<vector<char>> &g, int &h, int &w) {
  for(int i=0; i<h; i++) {
    bool f = true;
    for(int j=0; j<w; j++) {
      if(g.at(i).at(j) == '#') {
        f = false;
      }
    }
    if(f) {
      for(int j=i; j<h-1; j++) {
        for(int k=0; k<w; k++) {
          g.at(j).at(k) = g.at(j+1).at(k);
        }
      }
      g.pop_back();
      h--;
      return true;
    }
  }
  for(int i=0; i<w; i++) {
    bool f = true;
    for(int j=0; j<h; j++) {
      if(g.at(j).at(i) == '#') {
        f = false;
      }
    }
    if(f) {
      for(int j=0; j<h; j++) {
        for(int k=i; k<w-1; k++) {
          g.at(j).at(k) = g.at(j).at(k+1);
        }
        g.at(j).pop_back();
      }
      w--;
      return true;
    }
  }
  return false;
}
  

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> g(h, vector<char>(w));
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cin >> g.at(i).at(j);
    }
  }
  while(del(g, h, w));
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cout << g.at(i).at(j);
    }
    cout << endl;
  }
}
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w;
  cin >> h >> w;
  
  vector<string> v(h);
  for(int i=0; i<h; i++) cin >> v[i];
  
  vector<bool> tate(h, false);
  vector<bool> yoko(w, false);
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      if(v[i][j] == '#') {
        tate[i] = true;
        yoko[j] = true;
      }
    }
  }
  
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      if(tate[i] == true && yoko[j] == true) {
        cout << v[i][j];
      }
    }
    if(tate[i] == true) cout << endl;
  }
  return 0;
}
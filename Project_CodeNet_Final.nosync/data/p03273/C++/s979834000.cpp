#include <bits/stdc++.h>
using namespace std;
int main(){
  int h, w; cin >> h >> w;
  vector<string> ss(h);
  vector<bool> hh(h, false), ww(w, false);
  for (int i = 0; i < h; i++){
    string s; cin >> s; ss[i] = s;
    for (int j = 0; j < w; j++) {
      if (s[j] == '#') {
        hh[i] = true; ww[j] = true;
      }
    }
  }
  for (int i = 0; i < h; i++){
    if (!hh[i]) continue;
    for (int j = 0; j < w; j++) {
      if (!ww[j]) continue;
      cout << ss[i][j];
    }
    cout << endl;
  }
  return 0;
}
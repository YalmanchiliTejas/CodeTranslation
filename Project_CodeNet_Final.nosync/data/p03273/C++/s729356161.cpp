#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  string c(w, '.');
  for(int i = 0; i < h; i++) cin >> s[i];
  vector<bool> hh(h, true);
  vector<bool> ww(w, true);
  for(int i = 0; i < h; i++){
    if(s[i] == c) hh[i] = false;
  }
  for(int i = 0; i < w; i++){
    bool flag = true;
    for(int j = 0; j < h; j++){
      if(s[j][i] == '#') flag = false;
    }
    if(flag) ww[i] = false;
  }
  for(int i = 0; i < h; i++){
    if(hh[i]){
      for(int j = 0; j < w; j++){
	if(ww[j]) cout << s[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int H,W;
  cin >> H >> W;
  
  vector<vector<char>> vec2(H, vector<char>(W, '#'));
  for (int i=0; i<vec2.size()/*==H*/; i++) {
    for (int j=0; j<vec2.at(i).size()/*==W*/; j++) cin >> vec2.at(i).at(j);
  }
  
  for (int i=0; i<vec2.size()/*==H*/; i++) {
    int s=1;
    for (int j=0; j<vec2.at(i).size()/*==W*/; j++) {
      if (vec2.at(i).at(j)=='.') s*=1;
      else s*=0;
    }
    if (s==1) {
      for (int j=0; j<vec2.size()-i-1; j++) vec2.at(i+j)=vec2.at(i+j+1);
      vec2.pop_back();
      i-=1;
    }
  }
  
  for (int i=0; i<vec2.at(0).size()/*==W*/; i++) {
    int s=1;
    for (int j=0; j<vec2.size()/*<=H*/; j++) {
      if (vec2.at(j).at(i)=='.') s*1;
      else s*=0;
    }
    if (s==1) {
      for (int j=0; j<vec2.at(0).size()-i-1; j++) {
        for (int k=0; k<vec2.size(); k++) vec2.at(k).at(i+j)=vec2.at(k).at(i+j+1);
      }
      for (int k=0; k<vec2.size(); k++) vec2.at(k).pop_back();
      i-=1;
    }
  }
  
  for (int i=0; i<vec2.size(); i++) {
    for (int j=0; j<vec2.at(i).size(); j++) cout << vec2.at(i).at(j);
    cout << endl;
  }
}
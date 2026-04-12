// #include <bits/stdc++.h>
// #include "../00_Library/template.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
int main(){
  size_t h,w; cin >> h >> w;
  vector<string> s;
  string row(w,'.'); 
  for (int i = 0; i < h; i++)
  {
    string t; cin >> t;
    if(t==row) continue;
    s.push_back(t);
  }
  h = s.size();
  for (int j = 0; j < w; j++)
  {
    bool isEmpty = true;
    for (int i = 0; i < h; i++) {if(s[i][j]=='#') isEmpty=false;}
    if(isEmpty) {
      if(j==0) for (int i = 0; i < h; i++) s[i] = s[i].substr(1);
      else for (int i = 0; i < h; i++) s[i] = s[i].substr(0,j)+s[i].substr(j+1);
      w--;
      j--;
      }
  }
  
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cout << s[i][j];
    }
    cout << "\n";
  }
  // string te="123456789";
  // cout << te.substr(0,3) << te.substr(4) << endl;
  // cout << te.substr(2) << endl;
  

  return 0;
}

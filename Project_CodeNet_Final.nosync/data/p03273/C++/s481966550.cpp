#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>>hyo(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> hyo.at(i).at(j);
    }
  }
  for(int i=0;i<w;i++){
    bool c = true;
    for(int j=0;j<h;j++){
      if (hyo.at(j).at(i) == '#'){
        c = false;
        break;
      }
    }
    if(c){
      for(int j=0;j<h;j++){
        hyo.at(j).at(i) = ' ';
      }
    }
  }
  for(int i=0;i<h;i++){
    bool c = true;
    for(int j=0;j<w;j++){
      if (hyo.at(i).at(j) == '#'){
        c = false;
        break;
      }
    }
    if(c){
      for(int j=0;j<w;j++){
        hyo.at(i).at(j) = ' ';
      }
    }
  }
  for(int i=0;i<h;i++){
    bool c = false;
    for(int j=0;j<w;j++){
      if(hyo.at(i).at(j)!=' '){
      cout << hyo.at(i).at(j);
        c=true;
      }
    }
    if(c)
    cout << endl;
  }
}
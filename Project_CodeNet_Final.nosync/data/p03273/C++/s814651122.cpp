#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>>data(h,vector<char>(w));
  vector<vector<int>>plow(h,vector<int>(w,0));
  vector<vector<int>>pline(h,vector<int>(w,0));
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      cin >> data.at(i).at(j);
    }
  }
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if(data.at(i).at(j) == '#'){
        for(int k = 0;k < w;k++){
          plow.at(i).at(k) = 1;
        }
        break;
      }
    }
  }
  for(int i =  0;i < w;i++){
    for(int j = 0;j < h;j++){
      if(data.at(j).at(i) == '#'){
        for(int k = 0;k < h;k++){
          pline.at(k).at(i) = 1;
        }
        break;
      }
    }
  }
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if(plow.at(i).at(j) == 1 && pline.at(i).at(j) == 1){
        cout << data.at(i).at(j);
      }
      if(j == w-1){
        for(int k = 0;k < w;k++){
          if(plow.at(i).at(k) == 1 && pline.at(i).at(k) == 1){
            break;
          }
          if(k == w-1){
            goto pass;
          }
        }
        cout << endl;
        pass:;
      }
    }
  }
}

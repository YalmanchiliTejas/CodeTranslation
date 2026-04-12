#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w)), b(h, vector<char>(w)), c(h, vector<char>(w));
  for(int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < w; j++){
      a[i][j] = s[j];
    }
  }
  for(int i = 0; i < h; i++){
    bool white = false;
    for(int j = 0; j < w; j++) {
      if(a[i][j] == '.'){
        white = true;
      }else{
        white = false;
        break;
      }
    }
    if(white){
      for(int j = 0; j < w; j++){
        b[i][j] = '0';
      }
    }else{
      for(int j = 0; j < w; j++){
        b[i][j] = a[i][j];
      }
    }
  }


  for(int i = 0; i < w; i++){
    bool white = false;
    for(int j = 0; j < h; j++) {
      if(b[j][i]== '0'){
        white = true;
        continue;
      }
      if(b[j][i] == '.'){
        white = true;
      }else{
        white = false;
        break;
      }
    }
    if(white){
      for(int j = 0; j < h; j++){
        c[j][i] = '0';
      }
    }else{
      for(int j = 0; j < h; j++){
        c[j][i] = b[j][i];
      }
    }
  }
  for(int i = 0; i < h; i++){
    bool white = false;
    for(int j = 0; j < w; j++) {
      if(c[i][j] == '0') {
        white = true;
      }else{
        white = false;
        break;
      }
    }
    if(white){
      continue;
    }
    for(int j = 0; j < w; j++) {
      if(c[i][j] == '0') {
        continue;
      }
      cout << c[i][j];
    }
    cout << '\n';
  }
  return 0;
}
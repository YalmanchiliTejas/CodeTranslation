#include<bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  int a[100][100];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      char c;
      cin >> c;
      a[i][j] = (c == '.');
    }
  }
  bool f[100];
  fill(f, f + 100, true);
  for(int i = 0; i < h; i++){
    bool ff = true;
    for(int j = 0; j < w; j++){
      if(a[i][j] == 0){
        ff = false;
        f[j] = false;
      }
    }
    if(ff){
      for(int j = 0; j < w; j++){
        a[i][j] = -1;
      }
    }
  }
  for(int i = 0; i < w; i++){
    if(f[i]){
      for(int j = 0; j < h; j++){
        a[j][i] = -1;
      }
    }
  }
  for(int i = 0; i < h; i++){
    bool up = true;//全て-1なら改行しない
    for(int j = 0; j < w; j++){
      if(a[i][j] == 1){
        cout << '.';
        up = false;
      }else if(a[i][j] == 0){
        cout << '#';
        up = false;
      }
    }
    if(!up) cout <<endl;
  }
}
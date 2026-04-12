#include <bits/stdc++.h>
using namespace std;

int main(void){
  int H, W;
  cin >> H >> W;
  string a[H];
  for(int i=0; i<H; i++) cin >> a[i];
  
  bool tf = true;
  int h = H;
  int w = W;
  while(tf){
    // 行の抜き取り
    bool tf_R = true;
    for(int i = 0; i < h; i++){
      tf_R = true;
      for(int j = 0; j < w; j++){
        if(a[i][j] == '#') {
          tf_R = false;
          break;
        }
      }
      if(tf_R){
        for(int k=i; k<h-1; k++) swap(a[k], a[k+1]);
        h--;
        break;
      }
    }
    
    // 列の抜き取り
    bool tf_C = true;
    for(int i = 0; i < w; i++){
      tf_C = true;   
      for(int j = 0; j < h; j++){
        if(a[j][i] == '#') {
          tf_C = false;
          break;
        }
      }
      if(tf_C){
        for(int k=i; k<w-1; k++){
          for(int l=0; l<h; l++) swap(a[l][k], a[l][k+1]);
        }
        w--;
        break;
      }
    }
    tf = tf_R | tf_C;    
  }
  
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++){
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
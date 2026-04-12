#include <iostream>
#include <string>

using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  char a[H][W];
  char b[H][W];
  char c[H][W];
  int i,j,k,l;
  int h_flag= 0,w_flag= 0;
  l=0;
  for(i = 0; i < H; i++){
    for(j = 0;j < W;j++){
      cin >> a[i][j];
      if(a[i][j] == '#') w_flag= 1;
    }
    if(w_flag){
      for(k = 0;k < W;k++){
        b[l][k] = a[i][k];
      }
      l++;
    }
    w_flag = 0;
  }
  l = 0;
  for(i = 0; i < sizeof(b[0])/sizeof(b[0][0]); i++){
    for(j = 0; j < sizeof(b)/sizeof(b[0]);j++){
      if(b[j][i] == '#') h_flag = 1;
    }
    if(h_flag){
      for(k = 0;k < sizeof(b)/sizeof(b[0]);k++){
        c[k][l] = b[k][i];
      }
      l++;
    }
    h_flag = 0;
  }

  for(i = 0;i < sizeof(c)/sizeof(c[0]);i++){
    for(j = 0;j < sizeof(c[0])/sizeof(c[0][0]); j++){
      if(c[i][j] == '.' || c[i][j] == '#'){
        cout << c[i][j];
      }
    }
    cout << endl;
  }

  return 0;

}

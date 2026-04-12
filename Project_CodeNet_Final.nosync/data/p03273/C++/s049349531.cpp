#include <bits/stdc++.h>
using namespace std;

int main () {
 int H,W;
 cin >> H >> W;
 char b[H][W];
 int a[H][W];
  for(int i = 0;i < H;i++){
  	for(int j = 0; j < W;j++){
    	cin >> b[i][j];
      a[i][j] = 1;
    }
  }
  for(int i = 0;i < H;i++){
  	for(int j = 0; j < W;j++){
      if(b[i][j] == '#') break;
      if(j == W - 1){
        for(int k = 0;k < W;k++){
			a[i][k] = 0;
        }
      }
    }
  }
   for(int i = 0;i < W;i++){
  	for(int j = 0; j < H;j++){
      if(b[j][i] == '#') break;
      if(j == H - 1){
        for(int k = 0;k < H;k++){
			a[k][i] = 0;
        }
      }
    }
  }
  int c = 0;
  for(int i = 0;i < H;i++){
    c = 0;
  	for(int j = 0; j < W;j++){
      if(a[i][j] != 0){
        cout << b[i][j];
        c = 1;
      }
    }
    if(c == 1){
    cout << endl;
    }
  }
 return 0; 
}
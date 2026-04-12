#include<iostream>
using namespace std;
char a[100][100];
int H,W;
int main(){
  int flag = 0;
  int count = 0;
  cin >> H >> W;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> a[i][j];
    }
  }
  for(int i = 0; i < H; i++){
    flag = 1;
    for(int j = 0; j < W; j++){
      if(a[i][j] == '#'){
        flag = 0;
      }
    }
    if(flag){
      for(int j = 0; j < W; j++){
        a[i][j] = '0';
      }
    }
  }
  for(int j = 0; j < W; j++){
    flag = 1;
    for(int i = 0; i < H; i++){
      if(a[i][j] == '#'){
        flag = 0;
      }
    }
    if(flag){
      for(int i = 0; i < H; i++){
        a[i][j] = '0';
      }
    }
  }
  for(int i = 0; i < H; i++){
    count = 0;
    for(int j = 0; j < W; j++){
      if(a[i][j] != '0'){
        cout << a[i][j];
        count++;
      }
    }
    if(count != 0){
      cout << "\n";
    }
  }
  return 0;
}

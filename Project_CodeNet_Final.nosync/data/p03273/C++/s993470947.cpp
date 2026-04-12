#include<iostream>

using namespace std;

int main(){
  int H, W;
  char a[100][100];
  bool row[100] = {}, col[100] = {};
  
  cin >> H >> W;
  
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      cin >> a[i][j];
      if(a[i][j] == '#') row[i] = col[j] = true;
    }  
  }
  
  for(int i = 0;i < H;i++){
    if(!row[i]) continue;
    for(int j = 0;j < W;j++){
      if(!col[j]) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
  
  return 0;
}
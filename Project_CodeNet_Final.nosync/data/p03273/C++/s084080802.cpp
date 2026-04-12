#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;
int main(int argc,char** argv){
  int h,w;
  cin >> h >> w;
  bool height[h],width[w];
  for(int i = 0; i<h;i++){
    height[i] =false;
  }
  for(int j = 0; j<w;j++){
    width[j] =false;
  }

  char a[h][w];
  for(int i = 0; i<h;i++){
    for(int j = 0; j<w;j++){
      cin >> a[i][j];
      if(a[i][j] == '#'){
        height[i] = true;
        width[j] = true;
      }
    }
  }

  for(int i = 0;i<h;i++){
    if(height[i]){
      for(int j = 0;j<w;j++){
        if(width[j]){
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}

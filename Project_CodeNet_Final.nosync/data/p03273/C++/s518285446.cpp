#include <iostream>
using namespace std;

int main(){
  char a[101][101];
  int b[101] = {0}, c[101] = {0};
  int h, w;
  
  cin >> h >> w;
  
  for(int i = 0; i < h; i++ ){
    for(int j = 0; j < w; j++){
      cin >> a[i][j];
      if(a[i][j] == '#'){
        b[i] = 1;
        c[j] = 1;
      }
    }
  }
  
  for(int i = 0; i < h; i++ ){
    if(b[i] == 0) continue;
    for(int j = 0; j < w; j++){
      if(c[j] == 0) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
}
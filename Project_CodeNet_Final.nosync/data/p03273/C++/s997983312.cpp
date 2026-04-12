#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for(int i = 0; i < H; i++){
    cin >> a[i];
  }
  vector<bool> x(H,false);
  vector<bool> y(W,false);
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(a[i][j] == '#'){
        x[i] = true;
        y[j] = true;
      }
    }
  }
  for(int i = 0; i < H; i++){
    if(x[i]){
      for(int j = 0; j < W; j++){
        if(y[j]){
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}
#include <iostream>
#include <string>
using namespace std;
int H, W;
string a[100];
bool x[100], y[100];
int main(){
  cin >> H >> W;
  for(int i = 0; i < H; i++){
    cin >> a[i];
  }
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
#include <iostream>
#include <string>
using namespace std;

char c[100][100];

int rowFilled[100];
int colFilled[100];

int main(){
  int H,W;
  cin >> H >> W;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >>c[i][j];
      if(c[i][j]=='#'){
        rowFilled[j] = 1;
        colFilled[i] = 1;
      }
    }
  }


  for (int i = 0; i < H; ++i) {
    if(colFilled[i]==0) {
      continue;
    }

    for (int j = 0; j < W; ++j) {
      if(rowFilled[j]==1) {
        cout << c[i][j];
      }
    }
    puts("");

  }

  return 0;
}
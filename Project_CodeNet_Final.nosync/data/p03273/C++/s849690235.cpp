#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;

  char a[H][W];
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      cin >> a[i][j];
    }
  }

  bool r[H], c[W];
  fill(r, r+H, true);
  fill(c, c+W, true);

  for(int i = 0; i < H; ++i){
    r[i] = !all_of(&a[i][0], &a[i][W], [](const char c) { return c == '.';});
  }

  for(int i = 0; i < W; ++i){
    int count = 0;
    for(int j = 0; j < H; ++j){
      if(a[j][i] == '.'){
        ++count;
      }
    }
    if(count == H){
      c[i] = false;
    }
  }
  for(int i = 0; i < H; ++i){
    if(r[i]){
      for(int j = 0; j < W; ++j){
        if(c[j]){
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
}
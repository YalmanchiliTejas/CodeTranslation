#include <iostream>

using namespace std;

int main(void)
{
  char a[100][100];
  int H, W;
  cin >> H >> W;

  int heightNum[100] = {0};
  int widthNum[100] = {0};

  for(int j = 0; j < H; j++){
    for(int i = 0; i < W; i++){
      cin >> a[j][i];
    }
  }

  for(int j = 0; j < H; j++){
    for(int i = 0; i < W; i++){
      if(a[j][i] == '#'){
        heightNum[j] = 1;
        break;
      }
    }
  }

  for(int i = 0; i < W; i++){
    for(int j = 0; j < H; j++){
      if(a[j][i] == '#'){
        widthNum[i] = 1;
        break;
      }
    }
  }

  for(int j = 0; j < H; j++){
    if(heightNum[j] == 0){
      continue;
    }
    for(int i = 0; i < W; i++){
      if(widthNum[i] == 0){
        continue;
      }
      cout << a[j][i];
    }
    cout << endl;
  }

  return 0;
}

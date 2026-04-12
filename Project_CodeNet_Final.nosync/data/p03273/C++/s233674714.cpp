#include <iostream>

int main(void) {
  int H, W;
  std::cin >> H >> W;
  int tmp[W];
  char a[H][W];
  int flag = 0;
  int Hminace = 0;
  int Wminace = 0;
  int Huse[H];
  int Wuse[W];
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      std::cin >> a[i][j];
    }
  }

  for (int i = 0; i < H; ++i) {
    flag = 0;
    for (int j = 0; j < W; ++j) {
      if (a[i][j] != '.') {
        flag = 1;
      }
    }
    if (flag == 1) {
      Huse[i] = 1;
    }
    else {
      Huse[i] = 0;
    }
  }


  for (int j = 0; j < W; ++j) {
    flag = 0;
    for (int i = 0; i < H; ++i) {
      if (a[i][j] != '.') {
        flag = 1;
      }
    }
    if (flag == 1) {
      Wuse[j] = 1;
    }
    else {
      Wuse[j] = 0;
    }
  }


  for (int i = 0; i < H; ++i) {
    if (Huse[i] == 1) {
      flag = 0;
      for (int j = 0; j < W; ++j) {
        if (Wuse[j] == 1) {
          std::cout << a[i][j];
          flag = 1;
        }
      }
      if (flag == 1) {
        std::cout << std::endl;
      }
    }
  }
  return 0;
}

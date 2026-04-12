#include <stdio.h>
#include <iostream>

bool calc1(char** arr, int height, int width, int i, int j) {
  if(i < 0 || height <= i || j < 0 || width <= j)
    return false;
  if(i == height - 1 && j == width - 1) {
    if(arr[i][j] =='#')
      return true; 
    else
      return false;
  }
  if(arr[i][j] == '.') return false;
  if(calc1(arr, height, width, i + 1, j)) return true;
  if(calc1(arr, height, width, i, j + 1)) return true;
  return false;
}

int sumup(char* arr, int len) {
  int n = 0;
  for(int i = 0; i < len; i++)
    if(arr[i] == '#') n++;
  return n;
}

int main(void) {
  int h, w;
  std::cin >> h;
  std::cin >> w;
  char** arr = new char*[h];
  for(int i = 0; i < h; i++) {
    arr[i] = new char[w];
  }
  int n = 0;
  for(int i = 0; i < h; i++) {
    std::cin >> arr[i];
    n += sumup(arr[i], w);
  }
  if(n == (h + w - 1) && calc1(arr, h, w, 0, 0))
    std::cout << "Possible\n";
  else
    std::cout << "Impossible\n";
  return 0;
}
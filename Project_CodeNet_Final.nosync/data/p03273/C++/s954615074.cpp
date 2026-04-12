#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int main() {
  int h, w;
  cin >> h >> w;
  int Hcheck[h], Wcheck[w];
  char a[h][w];
  for (int i = 0; i < h; i++) {
    Hcheck[i] = 0;
  }
  for (int i = 0; i < w; i++) {
    Wcheck[i] = 0;
  }
  
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      if (a[i][j]=='#') {
        Hcheck[i] = 1;
        Wcheck[j] = 1;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (Hcheck[i] == 1 && Wcheck[j] == 1) {
        cout << a[i][j];
      }
    }
    if (Hcheck[i] == 1) {
      cout << endl;
    }
  }
  
}
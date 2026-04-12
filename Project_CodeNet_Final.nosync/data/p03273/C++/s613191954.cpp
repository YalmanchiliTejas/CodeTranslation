#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main(){
  int h,w;
  cin >> h >> w;
  std::vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }

  std::vector<bool> row(h,false),column(w,false);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        row[i] = true; column[j] = true;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    if (row[i]) {
      for (int j = 0; j < w; j++) {
        if (column[j]) {
          std::cout << a[i][j];
        }
      }
      std::cout << '\n';
    }
  }
}

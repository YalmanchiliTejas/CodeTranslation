#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;

int main() {
  int h, w;
  cin >> h >> w;
  char a[h][w];
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cin >> a[i][j];
    }
  }
  for (int i=0; i<h; i++) {
    bool flg=true;
    for (int j=0; j<w; j++) {
      if (a[i][j] == '.') flg = flg && true;
      else flg = flg && false;
    }
    if (flg) {
      for (int j=0; j<w; j++) {
        a[i][j] = '-';
      }
    }
  }

  for (int j=0; j<w; j++) {
    bool flg=true;
    for (int i=0; i<h; i++) {
      if (a[i][j] == '.' || a[i][j] == '-') flg = flg && true;
      else flg = flg && false;
    }
    if (flg) {
      for (int i=0; i<h; i++) {
        a[i][j] = '-';
      }
    }
  }

  for (int i=0; i<h; i++) {
    bool isout=false;
    for (int j=0; j<w; j++) {
      if (a[i][j] != '-') {
        cout << a[i][j];
        isout = true;
      }
    }
    if (isout) cout << endl;
  }

}

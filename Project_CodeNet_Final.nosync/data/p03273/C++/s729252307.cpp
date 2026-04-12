#include <bits/stdc++.h>
#define dum(x) cout<<#x<<'='<<x<<endl
#define ll long long
using namespace std;

char a[100][100];
char b[100][100];
int tate = 0;
int yoko = 0;

bool check(int t, int y) {
  bool f1 = false;
  bool f2 = false;

  for (int i = 0; i < 100; ++i) {
    if (a[t][i] == '#') {
      f1 = true;
    }
  }

  for (int j = 0; j < 100; ++j) {
    if (a[j][y] == '#') {
      f2 = true;
    }
  }

  if (f1 && f2) {

    return true;

  } else {
    return false;
  }
}

int main() {
  int h, w;
  cin >> h >> w;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < h; ++i) {
    bool flag = false;
    for (int j = 0; j < w; ++j) {
      if (check(i, j)) {
        cout << a[i][j];
        flag = true;
      }
    }
    if (flag) {
      cout << endl;
    }
  }
}

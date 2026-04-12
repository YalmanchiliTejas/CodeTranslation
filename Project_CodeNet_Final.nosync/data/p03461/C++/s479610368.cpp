#include <iostream>
using namespace std;

int d[15][15];

int s[105][105];

int main() {
  int a, b;
  cin >> a >> b;
  for (int ai = 1; ai <= a; ai++) {
    for (int bi = 1; bi <= b; bi++) {
      cin >> d[ai][bi];
    }
  }
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      int ss = 0;
      for (int ai = 1; ai <= a; ai++) {
        for (int bi = 1; bi <= b; bi++) {
          int sss = d[ai][bi] - ai * i - bi * j;
          if (sss > ss) ss = sss;
        }
      }
      s[i][j] = ss;
    }
  }
  bool feasible = true;
  for (int ai = 1; ai <= a; ai++) {
    for (int bi = 1; bi <= b; bi++) {
      int dd = 999999999;
      for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
          int ddd = ai * i + bi * j + s[i][j];
          if (ddd < dd) dd = ddd;
        }
      }
      if (dd != d[ai][bi]) feasible = false;
    }
  }
  if (feasible) {
    cout << "Possible" << endl;
    cout << "202 10401" << endl;
    for (int i = 0; i < 100; i++) {
      cout << i + 1 << " " << i + 2 << " X" << endl;
    }
    for (int i = 0; i < 100; i++) {
      cout << i + 102 << " " << i + 103 << " Y" << endl;
    }
    for (int i = 0; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
        cout << i + 1 << " " << 202 - j << " " << s[i][j] << endl;
      }
    }
    cout << "1 202" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
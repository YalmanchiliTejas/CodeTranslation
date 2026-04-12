#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int R[6][6] = {
    { 4, 0, 2, 1, 3, 5 },
    { 2, 1, 3, 5, 4, 0 },
    { 5, 1, 0, 2, 4, 3 },
    { 1, 3, 2, 4, 0, 5 },
    { 0, 5, 1, 3, 2, 4 },
    { 0, 2, 4, 3, 5, 1 }
  };
  map<string, int> T;
  T["North"] = 0;
  T["East"] = 1;
  T["West"] = 2;
  T["South"] = 3;
  T["Right"] = 4;
  T["Left"] = 5;
  for (;;) {
    int n, r = 1, t[6], d[6];
    cin >> n;
    if (!n) return 0;
    d[0] = 1;
    d[1] = 2;
    d[2] = 3;
    d[3] = 6;
    d[4] = 5;
    d[5] = 4;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int i = 0; i < 6; i++)
        t[R[T[s]][i]] = d[i];
      for (int i = 0; i < 6; i++)
        d[i] = t[i];
      r += d[0];
    }
    cout << r << endl;
  }
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  vector<bool> row(h, false);
  vector<bool> col(w, false);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    if (row[i]) {
      for (int j = 0; j < w; j++) {
        if (col[j]) {
          cout << s[i][j];
        }
      }
      cout << endl;
    }
  }

  return 0;
}

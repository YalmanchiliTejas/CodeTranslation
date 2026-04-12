#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int r[105], c[105], n, m, i, j;
  cin >> m >> n;
  string s[105];

  for (i = 0; i < m; i++) {
    cin >> s[i];
  }

  for (i = 0; i < m; i++) {
    r[i] = 0;
  }

  for (j = 0; j < n; j++) {
    c[j] = 0;
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (s[i][j] == '#') {
        r[i] = 1;
      }
    }
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (s[i][j] == '#') {
        r[i] = 1;
        c[j] = 1;
      }
    }
  }

  for (i = 0; i < m; i++) {
    if (r[i] == 0) {
      continue;
    } else {
      for (j = 0; j < n; j++) {
        if (c[j] == 0) {
          continue;
        } else {
          cout << s[i][j];
        }
      }
      cout << "\n";
    }
  }
  return 0;
}
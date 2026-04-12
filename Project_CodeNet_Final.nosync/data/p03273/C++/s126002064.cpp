#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)(100 + 5);

int h, w;
char field[MAX_N][MAX_N];

set<int> row;
set<int> col;

int main(void) {
  // Here your code !
  scanf("%d %d", &h, &w);

  for (int i = 0; i < h; ++i) {
    scanf("%s", &field[i]);
  }

  for (int i = 0; i < h; ++i) {
    bool thisrow = true;
    for (int j = 0; j < w; ++j) {
      thisrow &= (field[i][j] != '#');
    }
    if (thisrow) {
      row.insert(i);
    }
  }

  for (int j = 0; j < w; ++j) {
    bool thiscol = true;
    for (int i = 0; i < h; ++i) {
      thiscol &= (field[i][j] != '#');
    }
    if (thiscol) {
      col.insert(j);
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (row.find(i) == row.end() && col.find(j) == col.end()) {
        printf("%c", field[i][j]);
      }
    }
    if (row.find(i) == row.end()) printf("\n");
  }

  return 0;
}
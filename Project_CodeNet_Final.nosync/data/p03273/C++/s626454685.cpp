
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

char buf[110][110];
int main(void) {
  int nRow, nCol;
  scanf("%d%d", &nRow, &nCol);
  REP(i, nRow) {
    scanf("%s", buf[i]);
  }
  REP(i, nRow) {
    bool need = false;
    REP(j, nCol) {
      if(buf[i][j] == '#') {
        need = true;
      }
    }
    if(!need) {
      continue;
    }

    REP(j, nCol) {
      need = false;
      REP(ii, nRow) {
        if(buf[ii][j] == '#') {
          need = true;
        }
      }
      if(need) {
        putchar(buf[i][j]);
      }
    }
    puts("");
  }
  return 0;
}

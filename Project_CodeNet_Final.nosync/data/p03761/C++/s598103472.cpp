
#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)


int hist[2][100];
char buf[100];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, 26) {
    hist[0][i] = 1111111;
  }
  REP(i, n) {
    scanf("%s", buf);
    for(int j = 0; buf[j]; ++j) {
      hist[1][buf[j]-'a']++;
    }
    REP(j, 26) {
      hist[0][j] = min(hist[0][j], hist[1][j]);
      hist[1][j] = 0;
    }
  }
  REP(i, 26) {
    REP(j, hist[0][i]) {
      putchar('a'+i);
    }
  }
  putchar('\n');
  return 0;
}

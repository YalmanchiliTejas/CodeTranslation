#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR (i, 0, n)
#define _ << " _ " <<
#define TRACE(x) cerr << #x << " = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
//#define debug
//#define TRACE(x)

using namespace std;

typedef long long llint;

const int MAXN = 15;

int h, w, cnt;
int ok[MAXN][MAXN];
char s[MAXN][MAXN];

int main(void) {
  scanf("%d %d",&h,&w);
  REP(i, h) scanf("%s",s[i]);
  REP(i, h) REP(j, w) cnt += s[i][j] == '#' ? 1 : 0;

  if (cnt != h + w - 1) {
    printf("Impossible\n");
    return 0;
  }
  
  for (int i = h - 1; i >= 0; --i)
    for (int j = w - 1; j >= 0; --j) {
      if (s[i][j] != '#') continue;
      if (i == h - 1 && j == w - 1) ok[i][j] = 1;
      if (i < h - 1) ok[i][j] |= ok[i+1][j];
      if (j < w - 1) ok[i][j] |= ok[i][j+1];
    }

  printf(ok[0][0] ? "Possible\n" : "Impossible\n");

  return 0;
}

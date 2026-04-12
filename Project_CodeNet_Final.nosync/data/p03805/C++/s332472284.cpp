
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)


bool g[10][10];
int perm[10];

int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a][b] = true;
    g[b][a] = true;
  }
  
  REP(i, n)
    perm[i] = i;
  int res = 0;
  do {
    if(perm[0] != 0)
      continue;
    bool ok = true;
    REP(i, n-1) {
      if (g[perm[i]][perm[i+1]] == false) {
        ok = false;
        break;
      }
    }
    if (ok)
      ++res;
  } while (next_permutation(perm, perm + n));
  printf("%d\n", res);
  return 0;
}

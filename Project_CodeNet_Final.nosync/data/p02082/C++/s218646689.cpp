#include <cstdio>

using namespace std;

int p, q, s, t, y, M;

int main(void) {
  scanf("%d%d%d%d%d%d", &s, &t, &p, &q, &M, &y);
  printf("%d\n", (t^s^y));
  return 0;
}


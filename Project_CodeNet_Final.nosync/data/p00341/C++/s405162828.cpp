#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void) {
  int a[12], i, j, s = 0;
  for(i = 0; i < 12; ++i)scanf("%d", &a[i]);
  sort(a, a + 12);
  for(i = 0; i < 3; ++i) for(j = 1; j < 4; ++j) if(a[i * 4] != a[i * 4 + j]) s = 1;
  if(!s) printf("yes\n");
  else printf("no\n");
  return 0;
}

#include <stdio.h>
int main() {
  int x,y,z,n=1;
  scanf("%d %d %d",&x,&y,&z);
  while (n*(y+z)+z<=x) {
    n++;
  }
  printf("%d\n",n-1);
  return 0;
}
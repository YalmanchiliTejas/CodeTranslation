#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x;
  scanf("%d",&x);
  int k = 0;
  if(2<x) {
    if(x<8) {
      if(x%2==1) {
        k = 1;
      }
    }
  }
  if(k > 0) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}

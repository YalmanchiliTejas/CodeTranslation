#include <stdio.h>

#define MaxN 300000
int a[MaxN], b[MaxN];

int main(void) {
  int n;
  scanf("%i", &n);
  
  for (int i = 0; i < n; i++) {
    scanf("%i", &a[i]);
  }
  
  int l = 0, r = n-1, f = 0;
  for (int i = n-1; i >= 0; i--) {
    if (f) {
      b[r--] = a[i]; 
    } else {
      b[l++] = a[i];
    }
    f ^= 1;
  }
  
  for (int i = 0; i < n; i++) {
    printf("%i ", b[i]);
  }
  puts("");
  
  return 0;
}
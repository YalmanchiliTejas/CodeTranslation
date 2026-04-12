#include <stdio.h>

int max(int a, int b) {
  return a > b ? a : b;
}
  
int main(void) {
  int n, i, j;
  scanf("%d", &n);
  int d[n];
  for(i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
    d[i] /= 10;
  }
  int now = 0, s = 0;
  while(1) {
    int max = 0, maxn;
    if(!d[now]) {
      printf("no\n");
      return 0;
    }
    for(i = now; i <= now + d[now] && i < n; ++i) {
      if(i == n - 1) {
        s = 1;
        break;
      }
      if(max <= i + d[i]) max = i + d[i], maxn = i;
    }
    if(s) break;
    now = maxn;
  }
  s = 0, now = n - 1;
  //printf("2\n");
  while(1) {
    int min = 999999999, maxn;
    if(!d[now]) {
      printf("no\n");
      return 0;
    }
    for(i = now; i >= now - d[now] && i >= 0; --i) {
      if(i == 0) {
        s = 1;
        break;
      }
      if(min >= i - d[i]) min = i - d[i], maxn = i;
    }
    if(s) break;
    now = maxn;
  }
  printf("yes\n");
  return 0;
}

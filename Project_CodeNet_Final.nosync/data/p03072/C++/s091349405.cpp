#include <stdio.h>
#include <string.h>
int main(){
  int n;
  int h[101];
  int first;
  int sum = 0;

  scanf("%d", &n);

  int highest = 0;

  for(int cnt = 0; cnt < n; cnt++){
    scanf("%d", &h[cnt]);
    
    int ok = 1;
    if (h[cnt] >= highest) {
      sum++;
      highest = h[cnt];
    }
  }

  printf("%d", sum);
  printf("\n");
  
}

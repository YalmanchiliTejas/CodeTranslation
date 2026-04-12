#include <stdio.h>
#include <string.h>
int main(){
  int n;
  int h[101];
  int highest = 0;
  int sum = 0;

  scanf("%d", &n);

  for(int cnt = 0; cnt < n; cnt++){
    scanf("%d", &h[cnt]);
    if(h[cnt] >= highest){ 
      sum++;
      highest = h[cnt];
    }

  }

  printf("%d", sum);
  printf("\n");
  
}

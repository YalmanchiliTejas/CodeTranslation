#include <stdio.h>
#define N 150
int main(void)
{
  int i,j,n,h[N]={},ct=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",h+i);
  }
  ct++;
  for(i=1;i<n;i++){
    for(j=0;j<i;j++){
      if(h[i]<h[j]){
        break;
      }
      if(j==i-1){
        ct++;
      }
    }
  }
  printf("%d\n",ct);
  return 0;
}

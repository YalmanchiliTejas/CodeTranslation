#include<stdio.h>
int main(void)
{
  int n,h[100],count,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&h[i]);
  }

  count = 1;
  int max = h[0];
  for(i=1;i<n;i++){
    if(h[i] >= max){
      max = h[i];
      count += 1;
    }
  }

  printf("%d\n",count);
  return 0;
}


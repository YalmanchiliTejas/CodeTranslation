#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main()
{
  int N,count,i,j,flag;
  scanf("%d",&N);
  
  int H[N];
  
  for(i=0;i<N;i++){
    scanf("%d",&H[i]);
  }
  
  count=1;
  for(i=1;i<N;i++){
    flag=0;
    for(j=0;j<i;j++){
      if(H[j]>H[i]){
        flag=1;
        break;
      }
    }
    if(flag==0){
      count++;
    }
  }
  
  printf("%d",count);
  return 0;

}
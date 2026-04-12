#include<stdio.h>
int main(void){
  int N;
  scanf("%d",&N);
  int H[N],i,max,sum=1;
  for(i=0;i<N;i++) scanf("%d",&H[i]);
  max=H[0];
  for(i=1;i<N;i++){
    if(H[i]>=max){
      max=H[i];
      sum++;
    }
  }
  printf("%d",sum);
  return 0;
}
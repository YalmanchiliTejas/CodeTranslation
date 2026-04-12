#include <stdio.h>

int main(void){
  int a[3];
  for(int i=0;i<3;i++){
    scanf("%d",&a[i]);
  }
  int num=(a[0]*100)+(a[1]*10)+a[2];
  if(num%4==0){
    printf("YES");
  }else{
    printf("NO");
  }
  printf("\n");
  return 0;
}
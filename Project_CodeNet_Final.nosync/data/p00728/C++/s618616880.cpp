#include  <stdio.h>

int main(void){

  int size=0;
  int max=0;
  int min=1000;
  int num=0;
  int sum=0;
  while(1){

    min=1000;
    max=0;
    sum=0;
    scanf("%d",&size);
    if(size==0){
      break;
    }
    for(int i=0;i<size;i++){
      scanf("%d",&num);
      sum+=num;
  //    printf("::%d\n",sum);
      if(num<min){
        min=num;
      }
      if(num>max){
        max=num;
      }
    }
//    printf("%d %d",min,max);
    sum=((sum-max)-min)/(size-2);
    printf("%d\n",sum);
}
return 0;
}


#include<stdio.h>
int main(void){
  
    int a=0;
    int b=0;
    int c=0;
    int A[30];
    int d;
    int r=1;
        scanf("%d",&a);
  for(b=0;b<a;b++){
      scanf("%d",&A[b]);
  }
  for(b=1;b<a;b++){
      for(d=0;d<b;d++){
      if(A[b]>=A[d]){
          c=c+1;
      }
  }
  if(b==c){
r=r+1;

  }
  c=0;
  }
printf("%d",r);
}


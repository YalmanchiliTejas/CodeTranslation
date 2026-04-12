#include<stdio.h>
int main(){
  int e[12],i,kount=0,n=0,num;

  for(i=0;i<12;i++){
    scanf("%d",&e[i]);
  }

  while(n<12){
    num=e[n];
    for(i=0;i<12;i++){
      if(e[i]==num){
	kount++;
      }
    }
    if(kount%4!=0){
      printf("no\n");
      return 0;
    }
    n++;
    kount=0;
  }
  printf("yes\n");
  return 0;
}

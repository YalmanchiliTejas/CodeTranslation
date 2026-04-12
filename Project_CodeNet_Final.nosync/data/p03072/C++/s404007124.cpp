#include <stdio.h>

int main(){
 int n,i,sum=0,max;
  
  scanf("%d",&n);
  
  int a[100]={0};
  for(i=0;i<n;i++){
    scanf("%d ",&a[i]);
  }
  max=a[0];
  for(i=0;i<n;i++){
  if(max<=a[i+1]){
   sum++;
    max=a[i+1];
  }
  }
  
  printf("%d",sum+1);
  
  return 0;
  }
 
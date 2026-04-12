#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  int i,b;
  for(i=0;i<n;i++){
    scanf("%d",&b);
    a[i] = b;
  }
  int max = 0;
  int count = 0;
  for(i=0;i<n;i++){
    if(a[i] >= max){
      count++;
      max = a[i];
    }
  }

  printf("%d\n",count);
}
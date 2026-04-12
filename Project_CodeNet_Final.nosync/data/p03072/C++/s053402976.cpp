#include <stdio.h>

int main() {
  
  int count;
  scanf("%d",&count);
  int height[count];
  for(int i=0; i<count; ++i){
  	scanf("%d",&height[i]);
  }
  int highest = 0;
  int sum = 0;
  for(int i=0; i<count; i=i+1){
   if(highest <= height[i]){
     	highest = height[i];
   		sum = sum + 1;
   }
  }
  
  printf("%d\n", sum);
  return 0;
}
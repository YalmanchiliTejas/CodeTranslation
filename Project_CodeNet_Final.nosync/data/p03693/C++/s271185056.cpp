
#include <stdio.h>
#include <stdlib.h>
 
int main(void){
 
  char str[4];
 
  int i;
  scanf("%c %c %c",&str[0],&str[1],&str[2]);
  str[3] = '\0';
 
  if(atoi(str)%4 == 0){
    printf("YES");
  }else{
    printf("NO");
  }
 
  return 0;
 
}

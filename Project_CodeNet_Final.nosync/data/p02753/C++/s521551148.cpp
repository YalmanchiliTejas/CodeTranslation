#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[8];
  
  scanf("%s\n",str);
  
  if(strcmp(str,"AAA")== 0){
    printf("No");
  }else if(strcmp(str,"BBB")==0){
    printf("No");
  }else{
    printf("Yes");
  }
}
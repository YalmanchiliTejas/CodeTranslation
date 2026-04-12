#include <stdio.h>
#include <string.h>
int main(void){
  char s[3];
  scanf("%s", s);
  
  if(!strcmp(s, "AAA") || !strcmp(s, "BBB")){
    printf("No\n");
  }
  else{
    printf("Yes\n");
  }
  return 0;
}
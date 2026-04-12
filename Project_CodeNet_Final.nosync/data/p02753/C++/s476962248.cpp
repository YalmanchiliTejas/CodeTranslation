#include <stdio.h>
#include "string.h" 
char s[4];
 
int main()
{
    scanf("%s",s);
    if(strcmp(s,"AAA")==0 ||strcmp(s,"BBB")==0){
        printf("No");
    }
    else{
        printf("Yes");
    }
  return 0;
}
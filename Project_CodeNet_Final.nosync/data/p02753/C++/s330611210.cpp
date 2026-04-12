#include<stdio.h>
#include<string.h>
int main(){
   char s[3];
   scanf("%s",s);
   if(strcmp(s,"AAA")==0||strcmp(s,"BBB")==0){
      printf("No");
   }else{
      printf("Yes");
   }
   return 0;
}
      

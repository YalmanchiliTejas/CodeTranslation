#include<stdio.h>
int main(void){
  char str[3];
  for(int i=0; i<3; i++){
    scanf("%s",str);
  }
  if((str[0]=='A')&&(str[1]=='A')&&(str[2]=='A')){
    printf("No");
  }else{
    if((str[0]=='B')&&(str[1]=='B')&&(str[2]=='B')){
      printf("No");
    }else{
    printf("Yes");
  }
  }
}
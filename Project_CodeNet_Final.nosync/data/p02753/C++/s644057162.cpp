#include<stdio.h>
int main(){
  char str[3];
  int a=0,b=0,i;
  scanf("%s",str);
  for(i=0;i<3;i++){
    if(str[i]=='A') a++;
    else b++;
  }
  if(a==0 || b==0)
    printf("No");
  else
    printf("Yes");
}
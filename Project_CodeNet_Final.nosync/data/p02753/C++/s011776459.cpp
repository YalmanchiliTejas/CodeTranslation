#include<stdio.h>
char in[5];
int main(){
  scanf("%s",in);
  if(in[0]==in[1]&&in[1]==in[2])printf("No\n");
  else printf("Yes\n");
}
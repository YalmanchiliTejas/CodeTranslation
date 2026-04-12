//うるるん
#include<stdio.h>
#include<string.h>
int main(void)
{
  int i,N;
  char ch[6];
 scanf("%s",ch);
  N=strlen(ch);
 
  
 
  for(i=0;i+1<N;i++){
    if(ch[i]=='A' && ch[i+1]=='C'){
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
 
  return 0;
}
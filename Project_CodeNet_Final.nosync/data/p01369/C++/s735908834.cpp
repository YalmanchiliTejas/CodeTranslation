#include <stdio.h>
#include <string.h>
 
 
int main() {
 
  char key[] = {'y','h','n','u','j','m','i','k','o','p','l','\0'};
  char str[33];
  int hand,cha,i,j;
 
 
 
 
  while(1) {
 
  scanf("%s",str);
 
  if(str[0] == '#') break;
 
 
  for(i=0;i<strlen(key); i++) {
 
    if(key[i] == str[0]) break;
 
  }
 
  //rgiht:0 left:1
  if(strlen(key) == i) hand = 1;
  else hand = 0;
 
  //printf("hand = %d\n",hand);
 
  cha = 0;
  for(i=1;i<strlen(str);i++) {
     
    for(j=0;j<strlen(key);j++) {
       
      if(hand ==  0 && str[i] == key[j]){
    break;
      } else if(hand ==  1 && str[i] == key[j]){
    hand = 0;
    cha++;
    break;
      }
    }
    if(hand == 0 && strlen(key) == j) {
      cha++;
      hand = 1;
    }
 
  }
     
   
  printf("%d\n",cha);
 
  }
 
 
 
  return 0;
 
}
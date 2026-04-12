#include <stdio.h>
#include <string.h>
int main(){
  int a=0,i,size;
  int k[50];
  char s[50];
  while(1){
    scanf("%s",s);
    if(s[0]=='#') break;
    size=strlen(s);
    for(i=0;i<size;i++){
      if(s[i]=='y'||s[i]=='u'||s[i]=='i'||s[i]=='o'||s[i]=='p'||s[i]=='h'||s[i]=='j'||s[i]=='k'||s[i]=='l'||s[i]=='n'||s[i]=='m'){
	k[i]=1;
      }
      else {
	k[i]=0;
      }
    }
    for(i=1;i<size;i++){
    if(k[i-1]==k[i]) continue;
    else {
      a++;
	}
    }
    printf("%d\n",a);
    a=0;
  }
  return 0;
}
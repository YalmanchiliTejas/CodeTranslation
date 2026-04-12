#include <stdio.h>
int main(){
  int count,i,cc;
  char data[33];
  while(1){
    for(i=0;i<32;i++){
      data[i]='0';
    }
    scanf("%s",data);
    if(data[0]=='#') break;
    if(data[0]=='q'||data[0]=='w'||data[0]=='e'||data[0]=='r'||data[0]=='t'||data[0]=='a'||data[0]=='s'||data[0]=='g'||data[0]=='z'||data[0]=='x'||data[0]=='c'||data[0]=='v'||data[0]=='b'||data[0]=='d'||data[0]=='f'){
      cc=1;
    }else if(data[0]=='y'||data[0]=='u'||data[0]=='i'||data[0]=='o'||data[0]=='p'||data[0]=='h'||data[0]=='j'||data[0]=='k'||data[0]=='l'||data[0]=='n'||data[0]=='m'){
      cc=2;
    }
    count=0;
    
    for(i=1;i<32;i++){
      if(data[i]=='q'||data[i]=='w'||data[i]=='e'||data[i]=='r'||data[i]=='t'||data[i]=='a'||data[i]=='s'||data[i]=='g'||data[i]=='z'||data[i]=='x'||data[i]=='c'||data[i]=='v'||data[i]=='d'||data[i]=='b'||data[i]=='f'){ 
    if(cc==2){
    count++;
    cc=1;  
    }
      }else if(data[i]=='y'||data[i]=='u'||data[i]=='i'||data[i]=='o'||data[i]=='p'||data[i]=='h'||data[i]=='j'||data[i]=='k'||data[i]=='l'||data[i]=='n'||data[i]=='m'){
    if(cc==1){
    count++;
    cc=2;
    }
      }
    }
    printf("%d\n",count);
  }
  return 0;
}
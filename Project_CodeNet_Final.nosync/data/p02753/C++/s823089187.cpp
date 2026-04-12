#include<stdio.h>
int main(){
   char S[3];
   int cnt=0;
   scanf("%s",S);
   for(int i=0;i<3;i++){
      if(S[i]==S[i+1]){
         cnt++;
      }
   }
   if(cnt==2){
      printf("No");
   }else{
      printf("Yes");
   }
   return 0;
}

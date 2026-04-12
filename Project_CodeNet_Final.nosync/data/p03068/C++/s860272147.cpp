#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(void){
    char a[12]; int b[50];
    int N,K,s;
    
    scanf("%d",&N);
   
    scanf("%s",a);
   
    scanf("%d",&K);
    
   for(int i=0;i<=N-1;i++){
       b[i]=(int)a[i];
   }
   
   for(int i=0;i<=N-1;i++){
       if((int)a[i] != b[K-1]){
           a[i]='*';
       }
   }
   
   printf(a);
    
   
        return 0;
    }


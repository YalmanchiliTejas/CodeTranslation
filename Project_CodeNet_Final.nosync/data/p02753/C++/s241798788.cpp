#include<stdio.h>

int main(){
    char S[4];
    scanf("%s",S);
    if((int)S[0] == (int)S[1] && (int)S[0] == (int)S[2]){
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }
    
}
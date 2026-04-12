#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    char S[3];
    scanf("%s",S);
    
    
    if(S[0]!=S[1]||S[2]!=S[1])    printf("Yes");
    else printf("No");
    return 0;
}
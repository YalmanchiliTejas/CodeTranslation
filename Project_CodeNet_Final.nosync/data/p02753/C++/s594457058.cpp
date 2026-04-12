#include <stdio.h>
#include <stdlib.h>

int main(void){
    char n[3];
    scanf("%s",n);
    
    if(n[0] == n[1]&&n[1] ==n[2]){
        printf("No");
    }
    else{
        printf("Yes");
    }
    return 0;
}
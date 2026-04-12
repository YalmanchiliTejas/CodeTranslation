#include <stdio.h>
int main (void){
    char str[5];
    int i,a;
    a=0;
    scanf("%s",str);
    for (i=0;i<4;i++){
        if (str[i]=='A' && str[i+1]=='C'){
            a=a+1;
        }
        else{
        }
    }
    if (a>0){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}

// Example program
#include <iostream>
#include <string>
#include <stdio.h>

int main()
{
    char a,b,c;
    scanf("%c%c%c",&a,&b,&c);
    if(a==b && b==c && c==a){
        printf("No");
    }
    else{
        printf("Yes");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char a[1000];
    scanf("%s",&a);
    for(int i=0;i<strlen(a);i++){
        if((a[i]==a[i+1] && a[i]!=a[i+2])||(a[i]==a[i+2] && a[i]!=a[i+1])){
        printf("Yes");
        break;}
        else if(a[i]==a[i+1] && a[i]==a[i+2]){
            printf("No");
            break;}}
    return 0;
}

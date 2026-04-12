#include <stdio.h>
#include <string.h>
int main()
{
    char s[50];
    scanf("%s",s);
    if (s[0]==s[1] && s[1]==s[2]){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    return 0;
}
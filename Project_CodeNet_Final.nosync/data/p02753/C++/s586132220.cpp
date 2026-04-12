#include<stdio.h>
int main(void)
{
    int i,a=0,b=0;
    char s[3];
        scanf("%s",s);
    for(i=0;i<3;i++){
        if(s[i]=='A') a++;
        if(s[i]=='B') b++;
    }
    if(a==3 || b==3){
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    return 0;
}
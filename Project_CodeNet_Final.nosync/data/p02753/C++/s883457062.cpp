#include<stdio.h>
#include<string.h>
int main(){
    char s[5];
    int c=0;
    scanf("%s",s);
    for(int i=1;i<3;i++){
        if(s[i]!=s[i-1])c++;
    }
    if(c) printf("Yes");
    else printf("No");
    return 0;
}

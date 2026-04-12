#include<stdio.h>
#include<string.h>
char s[10];
int i,p;
int main(){
    scanf("%s",s);
    p=0;
    for(i=1;s[i];i++) if(s[i-1]=='A' && s[i]=='C') p=1;
    if(p) printf("Yes\n"); else printf("No\n");
}

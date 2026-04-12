#include<iostream>
#include<cstdio>
#include<cstring>
#define reg register
#define LL long long
char s[5];
int main(){
    std::scanf("%s",s+1);
    int a=0,b=0;
    if(s[1]=='A') a=1;
    else b=1;
    if(s[2]=='A') a=1;
    else b=1;
    if(s[3]=='A') a=1;
    else b=1;
    if(a&&b) std::puts("Yes");
    else std::puts("No");
    return 0;
}
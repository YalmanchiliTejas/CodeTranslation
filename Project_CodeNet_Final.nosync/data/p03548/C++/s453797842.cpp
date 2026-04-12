#include<iostream>
#include<ctype.h>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return f?-x:x;
}
int main(){
    int a=read(),b=read(),c=read(); 
    printf("%d\n",(a-c)/(b+c));
    return 0;
}
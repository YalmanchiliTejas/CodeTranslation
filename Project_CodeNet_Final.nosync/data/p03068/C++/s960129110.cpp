#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
char a[15];
inline int read(){
	int x=0,t=1,c;
	while(!isdigit(c=getchar())) if(c=='-') t=-1;
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*t;
}
int main(){
	n=read();
	scanf("%s",a+1);
	k=read();
	for(int i=1;i<=n;i++)
	    if(a[i]!=a[k]) printf("*");else printf("%c",a[i]);
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

inline int read()
{
	int f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

int n,k;
char a[15];

int main()
{
	n=read();
	scanf("%s",a+1);
	k=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[k]) printf("%c",a[i]);
		else printf("*");
	}
	return 0;
}

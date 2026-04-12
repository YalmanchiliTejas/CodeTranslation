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

int n;
int a,m=-1,cnt;

int main()
{
	int i;
	n=read();
	for(i=1;i<=n;i++) 
	{
	    a=read();
	    if(a>=m) cnt++;
	    m=max(m,a);
	}
	printf("%d",cnt);
	return 0;
}

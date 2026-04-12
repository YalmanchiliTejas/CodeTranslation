#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 50
int n,cnt;
int a[MAXN],b[MAXN];
inline int read(){
	int x=0,t=1,c;
	while(!isdigit(c=getchar())) if(c=='-') t=-1;
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*t;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=max(b[i-1],a[i-1]);
	for(int i=1;i<=n;i++) if(b[i]<=a[i]) cnt++;
	printf("%d\n",cnt);
	return 0;
}

#include <bits/stdc++.h>
#define N 200006
using namespace std;
int n,m,x,y,t,a[N],s[N];
inline int read()
{
	int x=0,c=getchar(),f=1LL;while(c<'0'||c>'9')f=(c=='-'?-f:f),c=getchar();
	while(c>='0'&&c<='9')x=(x<<1LL)+(x<<3)+c-48,c=getchar();return f>0?x:-x;
}
void print(long long x)
{
	if(x>9)print(x/10);putchar(x%10+48);
}
int main()
{
	n=read();x=1;y=n;t=0;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=n;i>=1;i--){
		if(t==0)s[x++]=a[i];
		else s[y--]=a[i];
		t^=1;
	}
	for(int i=1;i<n;i++)printf("%d ",s[i]);printf("%d\n",s[n]);
}
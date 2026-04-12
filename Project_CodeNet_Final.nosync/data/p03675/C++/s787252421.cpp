#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[Maxn],ans[Maxn];
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	int lx=0,rx=n+1;
	for (int i=n;i;i--)
	{
		if ((n-i)%2==0) ans[++lx]=a[i]; else ans[--rx]=a[i];
	}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}

#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200005],b[200005];
inline int read()
{
	char ch=getchar(); int ans=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch<='9'&&ch>='0') ans=ans*10+ch-48,ch=getchar();
	return ans;
}
bool cmp(int x,int y){return x>y;}
int main()
{
	int n=read();
	for (int i=1; i<=n; i++) a[i]=read(),b[i]=a[i];
	sort(a+1,a+1+n,cmp);
	int x=n/2;
	for (int i=1; i<=n; i++)
	{
		int t=lower_bound(a+1,a+1+n,b[i])-a;
		if (t<=x) printf("%d\n",a[x]);
		else printf("%d\n",a[x+1]);
	}
	return 0;
}
#include <cstdio>

using namespace std;

const int maxn=2e5+1e2;

int a[maxn],b[maxn];

int getint()
{
	char ch;int b=1;
	for(ch=getchar();ch>'9'||ch<'0';ch=getchar())if(ch=='-')b=-1;
	int num=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar())num=num*10+ch-'0';
	return num*b;
}

int main()
{
	int n=getint();
	for(int i=1;i<=n;i++)a[i]=getint();
	int head=1,tail=n;
	for(int i=n;i>=1;i--)
	{
		int t=(n-i)&1;
		if(!t)
		{
			b[head++]=a[i];
		}
		else b[tail--]=a[i];
	}
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define gc getchar()
#define N 200010
using namespace std;
int a[N],b[N];
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
int main()
{
	int n=inn();
	for(int i=1;i<=n;i++) a[i]=b[i]=inn();
	sort(b+1,b+n+1);int k=n/2;
	for(int i=1;i<=n;i++)
		if(a[i]>=b[k+1]) printf("%d\n",b[k]);
		else printf("%d\n",b[k+1]);
	return 0;
}
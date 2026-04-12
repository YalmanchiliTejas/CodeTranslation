#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#define int long long
#define N 200010
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
}
int n,tot,phi,a[N],b[N];
map<int,int> vis;
signed main()
{
	n=read();int X=read();int M=read();
	int g=X;vis[g]=1;
	int ans=g,sum=0,len=0;
	a[tot=1]=g;
	for(int i=2;i<=n;i++)
	{
		g=(g*g)%M;
		if(vis[g])
		{
			n-=tot;
			len=tot-vis[g]+1;
			sum=a[tot]-a[vis[g]-1];
			for(int j=1;j<=len;j++)b[j]=a[vis[g]+j-1]-a[vis[g]+j-2];
			break;
		}
		a[tot+1]=a[tot]+g;
		tot++;
		vis[g]=i;
		ans+=g;
	}
	if(len)ans=ans+sum*(n/len);
	if(len)for(int i=1;i<=n%len;i++)ans+=b[i];
	printf("%lld\n",ans);
	return 0;
}
//7 2 1001

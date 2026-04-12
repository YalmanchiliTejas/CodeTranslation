#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX_N 55
#define int long long

using namespace std;

int n,ans=0;
int a[MAX_N];

inline bool check()
{
	for(int i=1;i<=n;i++) if(a[i]>=n) return false;
	return true;
}

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	while(!check())
	{
		int mx=0,id=0;
		for(int i=1;i<=n;i++) if(a[i]>mx) mx=a[i],id=i;
		int t=mx/n; a[id]-=t*n,ans+=t;
		for(int i=1;i<=n;i++) if(i!=id) a[i]+=t;
	}
	printf("%lld\n",ans);
}

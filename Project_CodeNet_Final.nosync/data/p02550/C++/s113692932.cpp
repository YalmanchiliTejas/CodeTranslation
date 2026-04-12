#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int x,m,a[100005],l,r;
long long f[100005],ans,sum,n;

int main()
{
	scanf("%lld%d%d",&n,&x,&m);
	f[1]=x%m;a[f[1]]=1;
	for (int i=2;i<=n;i++) {
		f[i]=f[i-1]*f[i-1]%m;
		if (a[f[i]]) {
			l=a[f[i]];r=i;break;
		}else a[f[i]]=i;
	}
	if (!r) {
		for (int i=1;i<=n;i++) ans+=f[i];
	}else {
		for (int i=1;i<l;i++) ans+=f[i];
		for (int i=l;i<r;i++) sum+=f[i];
		ans+=sum*((n-l+1)/(r-l));
		int t=(n-l+1)%(r-l);
		for (int i=1;i<=t;i++) ans+=f[i+l-1];
	}
	printf("%lld\n",ans);
	return 0;
}
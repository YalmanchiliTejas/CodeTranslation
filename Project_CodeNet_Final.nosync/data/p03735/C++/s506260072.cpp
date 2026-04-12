#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
const int N=5e5;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
pair<int,int>p[N];
int bug[N];
int main()
{
	int n=gi(),i,len=0,a,b,Rmax=-1,Rmin=1<<30,Bmax=-1,Bmin=1<<30,k=0,l,r;LL ans;
	for (i=1;i<=n;i++) {
		p[++len]=make_pair(a=gi(),i);
		p[++len]=make_pair(b=gi(),i);
		if (a>b) swap(a,b);
		Rmax=max(Rmax,b);
		Rmin=min(Rmin,b);
		Bmax=max(Bmax,a);
		Bmin=min(Bmin,a);
	}
	ans=1LL*(Rmax-Rmin)*(Bmax-Bmin);
	sort(p+1,p+1+len);
	for (l=r=1;(k+=!bug[p[r].second]++)<n;r++);
	for (;r<=len;++bug[p[++r].second]) {
		while (bug[p[l].second]>1) bug[p[l++].second]--;
		ans=min(ans,1LL*(Rmax-Bmin)*(p[r].first-p[l].first));
	}
	printf("%lld\n",ans);
	return 0;
}

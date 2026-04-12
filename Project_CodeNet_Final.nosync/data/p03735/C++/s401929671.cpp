#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int INF=2e9;
int n,max0,min0,vis[200001];
LL ans=0;
struct data {
	int x,y;
}a[200001],b[400001];
bool cmp(data p,data q) {
	return p.x<q.x;
}
void work() {
	for (int i=1;i<=n;i++) {
		b[i*2-1].x=a[i].x;
		b[i*2].x=a[i].y;
		b[i*2-1].y=b[i*2].y=i;
	}
	sort(b+1,b+n*2+1,cmp);
	int j=0,cnt=0;
	for (int i=1;i<=n*2;i++) {
		while (j<n*2&&cnt<n) {
			j++;
			if (!vis[b[j].y]) cnt++;
			vis[b[j].y]++;
		}
		if (cnt==n) ans=min(ans,(LL)(max0-min0)*(LL)(b[j].x-b[i].x));
		if (vis[b[i].y]==1) cnt--;
		vis[b[i].y]--;
	}
}
int main() {
	scanf("%d",&n);
	max0=-INF;
	min0=INF;
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&a[i].x,&a[i].y);
		max0=max(max0,max(a[i].x,a[i].y));
		min0=min(min0,min(a[i].x,a[i].y));
	}
	int nowmax=-INF,nowmin=INF;
	for (int i=1;i<=n;i++) {
		nowmin=min(nowmin,max(a[i].x,a[i].y));
		nowmax=max(nowmax,min(a[i].x,a[i].y));
	}
	ans=max0-nowmin;
	ans*=nowmax-min0;
	work();
	printf("%lld\n",ans);
	return 0;
}
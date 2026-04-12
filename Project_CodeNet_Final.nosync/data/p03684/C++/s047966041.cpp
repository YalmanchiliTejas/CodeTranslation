#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100003;
typedef pair<int,int> PII;
int n;
struct Vec{
	int x,y,id;
}a[MaxN];
inline bool cmp_x(const Vec& a,const Vec& b) { return a.x<b.x; }
inline bool cmp_y(const Vec& a,const Vec& b) { return a.y<b.y; }
struct Edge{
	int u,v,cost;
	inline bool operator < (const Edge& o) const { return cost<o.cost; }
}e[MaxN*2];
int tot;

int fa[MaxN],rk[MaxN];
int getfa(int x) {
	if (fa[x]!=x) fa[x]=getfa(fa[x]);
	return fa[x];
}

inline void uni(int a,int b) {
	a=getfa(a),b=getfa(b);
	if (a!=b) {
		if (rk[a]<rk[b]) {
			fa[a]=b;
			rk[b]+=a;
		} else {
			fa[b]=a;
			rk[a]+=b;
		}
	}
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		int x,y;
		scanf("%d%d",&x,&y);
		a[i].x=x,a[i].y=y,a[i].id=i;
	}
	sort(a+1,a+n+1,cmp_x);
	for (int i=2;i<=n;++i) {
		tot++;
		e[tot].u=a[i-1].id,e[tot].v=a[i].id,e[tot].cost=abs(a[i-1].x-a[i].x);
	}
	sort(a+1,a+n+1,cmp_y);
	for (int i=2;i<=n;++i) {
		tot++;
		e[tot].u=a[i-1].id,e[tot].v=a[i].id,e[tot].cost=abs(a[i-1].y-a[i].y);
	}
	for (int i=1;i<=n;++i) fa[i]=i,rk[i]=1;
	sort(e+1,e+tot+1);
	long long ans=0;
	for (int i=1;i<=tot;++i) {
		int u=e[i].u,v=e[i].v,c=e[i].cost;
		if (getfa(u)!=getfa(v)) {
			ans+=c;
			uni(u,v);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
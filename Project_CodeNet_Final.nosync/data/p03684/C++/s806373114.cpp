#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)

using namespace std;

typedef long long ll;
const int maxn=100005;

struct edge {
	int u,v,w;
	bool operator < (const edge &other) const {
		return w<other.w;
	}
}e[maxn<<1];
int now,n,en;
struct point {
	int x,y,id;
	bool operator < (const point &other) const {
		if(now) return x<other.x;
		return y<other.y;
	}
}a[maxn];
int f[maxn];
int find(int x) {
	return x==f[x]?x:f[x]=find(f[x]);
}

int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		a[i].id=i;
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	now=1;
	sort(a+1,a+n+1);
	rep(i,2,n) 
		e[++en]=(edge){a[i-1].id,a[i].id,a[i].x-a[i-1].x};
	now=0;
	sort(a+1,a+n+1);
	rep(i,2,n)
		e[++en]=(edge){a[i-1].id,a[i].id,a[i].y-a[i-1].y};
	rep(i,1,n) f[i]=i;
	sort(e+1,e+en+1);
	ll mst=0,cnt=n;
	rep(i,1,en) {
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)) {
			f[find(u)]=find(v);
			mst+=e[i].w;
			cnt--;
			if(cnt==1) break;
		}
	}
	printf("%lld\n",mst);
	return 0;
}
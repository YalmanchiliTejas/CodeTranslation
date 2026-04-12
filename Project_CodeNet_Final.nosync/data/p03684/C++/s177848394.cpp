#include <bits/stdc++.h>
#define N 100050
using namespace std;
typedef long long LL;
int n,x[N],y[N],a[N],b[N],fa[N],cnt;
LL ans = 0LL;

struct Edge{int a,b,v;}e[2*N];
bool cmp(Edge p1, Edge p2) {
	return p1.v < p2.v;
}


bool cmp1(int p1, int p2) {return x[p1] < x[p2];}
bool cmp2(int p1, int p2) {return y[p1] < y[p2];}

inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int gf(int x) {return fa[x]==x?x:fa[x]=gf(fa[x]);}
int main() {
	n = rd();
	for (int i=1;i<=n;i++) x[i] = rd(), y[i] = rd();

	for (int i=1;i<=n;i++) fa[i] = a[i] = b[i] = i;
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	
	for (int i=1;i<n;i++) e[++cnt] = (Edge){a[i], a[i+1], x[a[i+1]]-x[a[i]]};
	for (int i=1;i<n;i++) e[++cnt] = (Edge){b[i], b[i+1], y[b[i+1]]-y[b[i]]};
	
	sort(e+1,e+cnt+1,cmp);
	for (int i=1;i<=cnt;i++) {
		if (gf(e[i].a) != gf(e[i].b)) {
			fa[ gf(e[i].a) ] = gf(e[i].b);
			ans += e[i].v;
		}
	}
	cout << ans << endl;

	return 0;
}

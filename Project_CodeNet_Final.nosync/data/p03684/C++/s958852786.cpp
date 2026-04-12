// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int N=100000+10;

int n,m=0,x[N],y[N],Sx[N],Sy[N];

struct edge { int u,v,w; } e[N<<2];

int f[N*3];
int find(int x) { return x==f[x]?x:f[x]=find(f[x]); }

int Kruskal() {
	sort(e+1,e+m+1,[](edge a,edge b) { return a.w<b.w; });
	for (int i=1;i<=n*3;++i) f[i]=i;
	int ans=0;
	for (int i=1;i<=m;++i) {
		int u=find(e[i].u),v=find(e[i].v),w=e[i].w;
		if (u!=v) ans+=w,f[u]=v;
	}
	return ans;
}

int main() {
	n=read();
	for (int i=1;i<=n;++i) Sx[i]=x[i]=read(),Sy[i]=y[i]=read();
	sort(Sx+1,Sx+n+1); int cx=unique(Sx+1,Sx+n+1)-Sx-1;
	sort(Sy+1,Sy+n+1); int cy=unique(Sy+1,Sy+n+1)-Sy-1;
	for (int i=1;i<=n;++i) {
		x[i]=lower_bound(Sx+1,Sx+cx+1,x[i])-Sx;
		y[i]=lower_bound(Sy+1,Sy+cy+1,y[i])-Sy;
		e[++m]=(edge){i,x[i]+n,0};
		e[++m]=(edge){i,y[i]+n+cx,0};
	}
	for (int i=1;i<cx;++i) e[++m]=(edge){i+n,i+n+1,Sx[i+1]-Sx[i]};
	for (int i=1;i<cy;++i) e[++m]=(edge){i+n+cx,i+n+cx+1,Sy[i+1]-Sy[i]};
	printf("%d\n",Kruskal());
	return 0;
}
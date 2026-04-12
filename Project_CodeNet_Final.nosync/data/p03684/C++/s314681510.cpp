#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
struct node{int x,y,num;}p[N];
struct edge{int x,y,l;}eg[N*3];
int fa[N];
inline bool cmpx(node a,node b) {return a.x<b.x;}
inline bool cmpy(node a,node b) {return a.y<b.y;}
inline bool cmpl(edge a,edge b) {return a.l<b.l;}
inline int getf(int x) {
	if(fa[x]==x) return x;
	fa[x]=getf(fa[x]);
	return fa[x];
}
int main() {
	int n,tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].num=i;
		fa[i]=i;
	}
	sort(p+1,p+n+1,cmpx);
	for(int i=1;i<n;i++) eg[++tot]=(edge){p[i].num,p[i+1].num,(p[i+1].x-p[i].x)};
	sort(p+1,p+n+1,cmpy);
	for(int i=1;i<n;i++) eg[++tot]=(edge){p[i].num,p[i+1].num,(p[i+1].y-p[i].y)};
	sort(eg+1,eg+tot+1,cmpl);
	int a,b,ct=0,ans=0;
	for(int i=1;i<=tot;i++) {
		a=getf(eg[i].x);
		b=getf(eg[i].y);
		if(a==b) continue;
		ct++;
		ans+=eg[i].l;
		fa[a]=b;
		if(ct==n-1) break;
	}
	printf("%d\n",ans);
	return 0;
}
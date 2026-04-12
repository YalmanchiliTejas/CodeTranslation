#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100005;
inline int read(){
	int x=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,cnt=0,bel[maxn];
struct data{
	int x,y,id;
}p[maxn];
bool comp1(data d1,data d2){
	if (d1.x==d2.x) return d1.y<d2.y;
	return d1.x<d2.x;
}
bool comp2(data d1,data d2){
	if (d1.y==d2.y) return d1.x<d2.x;
	return d1.y<d2.y;
}
struct edge{
	int from,to,c;
}e[maxn<<1];
inline void add_edge(int from,int to,int c){
	e[cnt].from=from;e[cnt].to=to;e[cnt++].c=c;
}
inline bool cmp(edge e1,edge e2){
	return e1.c<e2.c;
}
int find(int x){
	if (bel[x]==x) return x;
	return bel[x]=find(bel[x]);
}
int main(){
	n=read();for (int i=1;i<=n;++i) bel[i]=i;
	for (int i=1;i<=n;++i) p[i].x=read(),p[i].y=read(),p[i].id=i;
	sort(p+1,p+n+1,comp1);
	for (int i=1;i<n;++i) add_edge(p[i].id,p[i+1].id,min(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y)));
	sort(p+1,p+n+1,comp2);
	for (int i=1;i<n;++i) add_edge(p[i].id,p[i+1].id,min(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y)));
	sort(e,e+cnt,cmp);ll ans=0;
	for (int i=0;i<cnt;++i){
		int x=find(e[i].from),y=find(e[i].to);
		if (x==y) continue;
		ans+=e[i].c;
		bel[x]=y;
	}
	printf ("%lld\n",ans);
	return 0;
}

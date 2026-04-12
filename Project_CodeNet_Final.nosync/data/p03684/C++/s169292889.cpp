#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e5+11,INF=~0u>>2;
struct Edge{int nxt,from,to,w;}edge[N<<2];
struct Point{int x,y,id;}p[N];
int n,num_edge,head[N],fa[N];
ll ans;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
void add_edge(int from,int to,int w){
	edge[++num_edge].nxt=head[from];
	edge[num_edge].to=to;
	edge[num_edge].w=w;
	edge[num_edge].from=from;
	head[from]=num_edge;
}
bool cmpx(Point a,Point b){
	return a.x<b.x;
}
bool cmpy(Point a,Point b){
	return a.y<b.y;
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void Kruskal(){
	sort(edge+1,edge+1+num_edge,cmp);
	for(int i=1;i<=n;++i) fa[i]=i;
	int cnt=0;
	for(int i=1;i<=num_edge;++i){
		int f1=find(edge[i].from),f2=find(edge[i].to);
		if(f1!=f2){
			cnt++;
			fa[f2]=f1;
			ans+=edge[i].w;
		}
		if(cnt==n-1) return;
	}
}
int main(){
//	freopen("ex.in","r",stsdin);
	n=read();
	for(int i=1;i<=n;++i){
		p[i].x=read();
		p[i].y=read();
		p[i].id=i;
	}
	sort(p+1,p+n+1,cmpx);
	for(int i=1;i<n;++i){
		add_edge(p[i].id,p[i+1].id,p[i+1].x-p[i].x);
//		add_edge(p[i+1].id,p[i].id,p[i+1].x-p[i].x);
	}
	sort(p+1,p+n+1,cmpy);
	for(int i=1;i<n;++i){
		add_edge(p[i].id,p[i+1].id,p[i+1].y-p[i].y);
//		add_edge(p[i+1].id,p[i].id,p[i+1].y-p[i].y);
	}
	Kruskal();
	printf("%lld",ans);
	return 0;
}
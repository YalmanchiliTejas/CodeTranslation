#include <bits/stdc++.h>
#define SIZE 100105
using namespace std;

struct point{
	int x;
	int y;
	int ind;
}p[SIZE], sx[SIZE], sy[SIZE];
bool cmpx(point a, point b){
	return a.x<b.x;
}
bool cmpy(point a, point b){
	return a.y<b.y;
}

struct edge{
	int u, v, w;
	edge(){};
	edge(int uu, int vv, int ww){
		u=uu;
		v=vv;
		w=ww;
	}
}ed[4*SIZE];

bool cmpw(edge a, edge b){
	return a.w<b.w;
}

int eds;
int n;
int par[SIZE];
int sz[SIZE];

int root(int x){
	if(par[x]==x) return x;
	return root(par[x]);
}

int merger(int u, int v, int w){
	u=root(u);
	v=root(v);
	if(u==v) return 0;
	if(sz[u]<sz[v]) swap(u, v);
	sz[u]+=sz[v];
	par[v]=par[u];
	return w;
}

void init(){
	for(int i=0; i<SIZE; i++){
		par[i]=i;
		sz[i]=1;
	}
}

void construct_edges(){
	sort(sx, sx+n, cmpx);
	sort(sy, sy+n, cmpy);
	eds=0;
	for(int i=0; i<(n-1); i++){
		ed[eds]=edge(sx[i].ind, sx[i+1].ind, sx[i+1].x-sx[i].x);
		eds++;
		ed[eds]=edge(sy[i].ind, sy[i+1].ind, sy[i+1].y-sy[i].y);
		eds++;
	}
	sort(ed, ed+eds, cmpw);
}

int kruskal(){
	int res=0;
	init();
	construct_edges();
	for(int i=0; i<eds; i++){
		res+=merger(ed[i].u, ed[i].v, ed[i].w);
	}
	return res;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].ind=i;
		sx[i]=sy[i]=p[i];
	}
	printf("%d\n", kruskal());
	return 0;
}

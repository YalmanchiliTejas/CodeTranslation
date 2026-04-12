#include<bits/stdc++.h>
#define maxn 100010
#define LL long long 
using namespace std;
struct Edge{
	int u,v,w;
}e[maxn*5];
int n,cnt=0,f[maxn];
LL ans=0;
struct Node{
	int x,y,pos;
}seg[maxn]; 
bool cmp1(Node a,Node b){
	if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
bool cmp2(Node a,Node b){
	if(a.y==b.y) return a.x<b.x;
	else return a.y<b.y;
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&seg[i].x,&seg[i].y);
		seg[i].pos=i;
		f[i]=i;
	}
	sort(seg+1,seg+1+n,cmp1);
	for(int i=2;i<=n;i++){
		e[++cnt].u=seg[i-1].pos;
		e[cnt].v=seg[i].pos;
		e[cnt].w=seg[i].x-seg[i-1].x; 
		e[++cnt].u=seg[i].pos;
		e[cnt].v=seg[i-1].pos;
		e[cnt].w=seg[i].x-seg[i-1].x;
	}
	sort(seg+1,seg+1+n,cmp2);
	for(int i=2;i<=n;i++){
		e[++cnt].u=seg[i-1].pos;
		e[cnt].v=seg[i].pos;
		e[cnt].w=seg[i].y-seg[i-1].y; 
		e[++cnt].u=seg[i].pos;
		e[cnt].v=seg[i-1].pos;
		e[cnt].w=seg[i].y-seg[i-1].y; 
	}
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int nx=find(e[i].u),ny=find(e[i].v);
		if(nx==ny) continue;
		ans+=e[i].w;
		f[nx]=ny;	
	}
	cout<<ans;
	return 0;
	
}
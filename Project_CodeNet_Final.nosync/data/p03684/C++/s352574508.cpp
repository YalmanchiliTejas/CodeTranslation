#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int mxn=100010;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct node{
	int x,y,id;
}a[mxn];
int cmp1(node a,node b){
	return a.x<b.x;
}
int cmp2(node a,node b){
	return a.y<b.y;
}
int n;
//
struct edge{
	int x,y,w;
	bool operator < (const edge &b)const{
		return w<b.w;
	}
}e[mxn*20];
int mct=0;
void add_edge(int u,int v,int w){
	e[++mct].x=u;e[mct].y=v;e[mct].w=w; return;
}
//
int fa[mxn];
int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
int ans=0;
void kruskal(){
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=1;
	sort(e+1,e+mct+1);
	for(int i=1;i<=mct;i++){
		int x=e[i].x,y=e[i].y;
		x=find(x);y=find(y);
		if(find(x)!=find(y)){
			fa[x]=y;
			cnt++;
			ans+=e[i].w;
		}
		if(cnt==n)break;
	}
	printf("%d\n",ans);
	return;
}
int main(){
	int i,j;
	n=read();
	for(i=1;i<=n;i++){
		a[i].x=read();a[i].y=read();
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp1);
	for(i=1;i<n;i++){
		add_edge(a[i].id,a[i+1].id,abs(a[i].x-a[i+1].x));
	}
	sort(a+1,a+n+1,cmp2);
	for(i=1;i<n;i++){
		add_edge(a[i].id,a[i+1].id,abs(a[i].y-a[i+1].y));
	}
	kruskal();
	return 0;
}
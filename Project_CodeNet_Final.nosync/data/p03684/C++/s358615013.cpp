#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int N=100005;
const int inf=1000000000;

struct node{
	int x,y,id;
}a[N];
struct E{
	int x,y,w;
	E(){}
	E(int x,int y,int w):x(x),y(y),w(w){}
}e[N<<1];
int n,m,ans,x,y;
int fa[N];

bool cmp1(node a,node b){
	return a.y<b.y;
}

bool cmp2(node a,node b){
	return a.x<b.x;
}

int find(int k){
	if (fa[k]!=k) fa[k]=find(fa[k]);
	return fa[k];
}

bool cmp(E a,E b){
	return a.w<b.w;
}

int main(){
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp1);
	for (i=1;i<n;i++) e[++m]=E(a[i].id,a[i+1].id,a[i+1].y-a[i].y);
	sort(a+1,a+1+n,cmp2);
	for (i=1;i<n;i++) e[++m]=E(a[i].id,a[i+1].id,a[i+1].x-a[i].x);
	sort(e+1,e+1+m,cmp);
	for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=m;i++){
		x=find(e[i].x); y=find(e[i].y);
		if (x!=y){
			fa[x]=y;
			ans+=e[i].w;
		}
	}
	printf("%d\n",ans);
	return 0;
}
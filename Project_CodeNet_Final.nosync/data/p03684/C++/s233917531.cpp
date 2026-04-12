#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005;
int n,tot,h[N],fa[N],cnt,ans;
struct node{
	int x,y,num;
}a[N];
struct edge{
	int u,v,w;
}e[2*N];
bool cmp1(node a,node b){
	return  a.x<b.x;
}
bool cmp2(node a,node b){
	return a.y<b.y;
}
bool cmp3(edge a,edge b){
	return a.w<b.w;
}
void ins(int u,int v,int w)
{
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
}
int find(int x)
{
	if(fa[x]==x)  return x;
	return fa[x]=find(fa[x]);
}
void unionn(int x,int y,int w)
{
	x=find(x),y=find(y);
	if(x==y)  return;
	cnt++;
	ans+=w;
	if(h[x]<h[y])
	{
		fa[x]=y;
		h[y]=max(h[y],h[x]+1);
	}
	else
	{
		fa[y]=x;
		h[x]=max(h[x],h[y]+1);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].num=i;
		fa[i]=i;
		h[i]=1;
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<n;i++)
	  ins(a[i].num,a[i+1].num,a[i+1].x-a[i].x);
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<n;i++)
	  ins(a[i].num,a[i+1].num,a[i+1].y-a[i].y);
	sort(e+1,e+tot+1,cmp3);
	for(int i=1;i<=tot&&cnt<=n-1;i++)
	{
		int x=e[i].u,y=e[i].v,w=e[i].w;
		unionn(x,y,w);
	}
	cout<<ans;
}
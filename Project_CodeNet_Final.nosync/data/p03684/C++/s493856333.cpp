#include<bits/stdc++.h>
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
	while(ch=getchar(),(ch>='0'&&ch<='9'))
		aa=aa*10+ch-48;
	return (bb?(-aa):(aa));
}
struct P
{
	int x,y,id;
} p[100010];
struct E
{
	int from,to,w;
} e[200010];
int tot=0,N,u,v,x,y,fu,fv;
long long ans=0;
int fa[100010];
bool cmpx(P u,P v){return u.x<v.x;}
bool cmpy(P u,P v){return u.y<v.y;}
bool cmp(E u,E v){return u.w<v.w;}
int find(int u)
{
	if(u!=fa[u])
		return fa[u]=find(fa[u]);
	return u;
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	{
		fa[i]=i;
		scanf("%d%d",&x,&y);
		p[i].x=x;
		p[i].y=y;
		p[i].id=i;
	}
	sort(p+1,p+N+1,cmpx);
	for(int i=1;i<N;++i)
	{
		e[++tot].from=p[i].id;
		e[tot].to=p[i+1].id;
		e[tot].w=p[i+1].x-p[i].x;
	}
	sort(p+1,p+N+1,cmpy);
	for(int i=1;i<N;++i)
	{
		e[++tot].from=p[i].id;
		e[tot].to=p[i+1].id;
		e[tot].w=p[i+1].y-p[i].y;
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=tot;++i)
	{
		u=e[i].from;
		v=e[i].to;
		fu=find(u);
		fv=find(v);
		if(fu!=fv)
		{
			fa[fu]=fv;
			ans+=e[i].w;
			//cout<<u<<" "<<v<<" "<<e[i].w<<endl;
		}
	}
	cout<<ans<<endl;
}
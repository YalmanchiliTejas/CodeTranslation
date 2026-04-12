#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define x first 
#define y second
typedef std::pair<int,int> pii;
typedef std::pair<pii,int> edg;
typedef std::pair<int,pii> kkk;
const int N=101000;
edg s[N];
kkk t[N<<1];
int n,m;
bool com(edg a,edg b){return a.x.y==b.x.y?a.x.x<b.x.x:a.x.y<b.x.y;}
int calc(int i,int j){return std::min(std::abs(s[i].x.x-s[j].x.x),std::abs(s[i].x.y-s[j].x.y));}
int q[N];
void init(){for(int i=1;i<=n;i++)q[i]=i;}
int ask(int p){return q[p]==p?p:q[p]=ask(q[p]);}
bool uni(int u,int v){return ask(u)==ask(v);}
void link(int u,int v){q[ask(u)]=ask(v);} 
int mt()
{
	int ret=0;
	init();
	std::sort(t+1,t+m+1);
	for(int i=1;i<=m;i++)
	{
		int x=t[i].y.x,y=t[i].y.y;
		if(uni(x,y))continue;
		link(x,y);
		ret+=t[i].x;
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++)
		scanf("%d%d",&x,&y),s[i]=edg(pii(x,y),i);
	std::sort(s+1,s+n+1);
	m=0;
	for(int i=1;i<n;i++)
		t[++m]=kkk(calc(i,i+1),pii(s[i].y,s[i+1].y));
	std::sort(s+1,s+n+1,com);
	for(int i=1;i<n;i++)
		t[++m]=kkk(calc(i,i+1),pii(s[i].y,s[i+1].y));
	printf("%d\n",mt());
	return 0;
}

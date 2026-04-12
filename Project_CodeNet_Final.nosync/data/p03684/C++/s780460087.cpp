using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 100001
struct dian{
	int x,y,no;
}xx[N],yy[N];
bool cmpx(dian hh,dian aa)
{
	return hh.x<aa.x;
}
bool cmpy(dian hh,dian aa)
{
	return hh.y<aa.y;
}
 
int x[N],y[N];
struct edge{
	int from,to,val;
}E[2*N];
bool cmp(edge hh,edge aa)
{
	return hh.val<aa.val;
}
int cnt=0;
int fa[N];
int ans;
int getf(int no)
{
	return fa[no]==no?no:fa[no]=getf(fa[no]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1;i<=n;i++) 
	{
		xx[i].x=x[i];xx[i].y=y[i];xx[i].no=i;
	}
	sort(xx+1,xx+n+1,cmpx);
	for(int i=1;i<=n-1;i++)
	{
		E[++cnt].from=xx[i].no;
		E[cnt].to=xx[i+1].no;
		E[cnt].val=xx[i+1].x-xx[i].x;
	}
	sort(xx+1,xx+n+1,cmpy);
	for(int i=1;i<=n-1;i++)
	{
		E[++cnt].from=xx[i].no;
		E[cnt].to=xx[i+1].no;
		E[cnt].val=xx[i+1].y-xx[i].y;
	}
	sort(E+1,E+cnt+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	int zkx=0;
	for(int i=1;i<=cnt;i++)
	{
		if(getf(E[i].from)!=getf(E[i].to))
		{
			fa[fa[E[i].from]]=fa[E[i].to];
			ans+=E[i].val;
			zkx++;
		}
		if(zkx==n-1) break;
	}
	cout<<ans<<endl; 
}
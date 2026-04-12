#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <time.h>
#include <set>
using namespace std;
const int N=100001;
struct node
{
	int d,p;
	bool operator<(const node &e)const
	{
		if(d<e.d)	return true;
		return false;
	};
}x[N],y[N];
struct edge
{
	int d;
	int u,v;
	bool operator<(const edge &e)const
	{
		if(d<e.d)	return true;
		return false;
	};
};
int n,a[N],b[N],f[N];
multiset<edge> s;
int dist(int x,int y)
{
	return min(abs(a[x]-a[y]),abs(b[x]-b[y]));
}
int findr(int x)
{
	if(x==f[x])	return x;
	return f[x]=findr(f[x]);
}
int uniont(int x,int y)
{
	int gx=findr(x),gy=findr(y);
	if(gx==gy)	return 0;
	f[gx]=gy;	return 1;
}
int main()
{
    int i;
	long long ans=0;
    cin>>n;
    for(i=1;i<=n;i++)
	{
		scanf("%d %d",&x[i].d,&y[i].d),x[i].p=y[i].p=i;
		a[i]=x[i].d,b[i]=y[i].d;
		f[i]=i;
	}
    sort(x+1,x+n+1);sort(y+1,y+n+1);
    for(i=1;i<=n-1;i++)
    {
    	edge tmp;
    	tmp.d=dist(x[i].p,x[i+1].p);
    	tmp.u=x[i].p,tmp.v=x[i+1].p;
    	s.insert(tmp);
    	//cout<<s.size()<<endl;
    	tmp.d=dist(y[i].p,y[i+1].p);
    	tmp.u=y[i].p,tmp.v=y[i+1].p;
    	s.insert(tmp);
    	//cout<<s.size()<<endl;
	}
	for(set<edge>::iterator l=s.begin();l!=s.end();l++)
		ans+=(long long)uniont(l->u,l->v)*l->d;
		//cout<<l->u<<' '<<l->v<<endl;*/
	cout<<ans;
	//for(i=1;i<=n;i++)	cout<<x[i].d<<' '<<x[i].p<<endl;
	return 0;
}

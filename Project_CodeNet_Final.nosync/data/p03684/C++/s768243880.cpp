#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int C=1000000007;
const int M=100010;

struct Edge
{
	int u,v,c;
	bool operator < (const Edge &b) const {return c<b.c;}
}e[M<<1];

struct Point
{
	int x,y,id;
}a[M];

bool cmp1(Point a,Point b)
{
	return a.x<b.x;
}

bool cmp2(Point a,Point b)
{
	return a.y<b.y;
}

ll ans;
int n,tot;
int f[M];

inline int getf(int x) {return f[x]==x?x:f[x]=getf(f[x]);}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i].x>>a[i].y,a[i].id=i;
	sort(a,a+n,cmp1);
	for(int i=0;i+1<n;i++)
		e[tot++]=(Edge){a[i].id,a[i+1].id,abs(a[i].x-a[i+1].x)};
	sort(a,a+n,cmp2);
	for(int i=0;i+1<n;i++)
		e[tot++]=(Edge){a[i].id,a[i+1].id,abs(a[i].y-a[i+1].y)};
	for(int i=0;i<n;i++)
		f[i]=i;
	sort(e,e+tot);
	for(int i=0;i<tot;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(getf(u)!=getf(v)) ans+=e[i].c,f[getf(u)]=getf(v);
	}
	cout<<ans;
	return 0;
}
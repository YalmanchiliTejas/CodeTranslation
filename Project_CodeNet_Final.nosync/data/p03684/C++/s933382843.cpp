#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define LOWBIT(x) x & (-x)
#define Pair pair<int,int>
#define LL long long
using namespace std;

const int MOD=1e9+7;
const int INF=0x7ffffff;

struct node
{
	int x,y;
	int num;
}a[100048];

struct node2
{
	int d;
	bool s;
	int num;
	friend bool operator < (const node2 &x,const node2 &y)
	{
		return x.d>y.d;
	}
};

int n;
map<int,bool> m;
map<int,int> rhao,chao;
int rt=0,ct=0;
vector<Pair> vr[100048],vc[100048];
priority_queue<node2> qr,qc;

Pair r[100048],c[100048];

bool cmp1(node x,node y)
{
	return x.x<y.x;
}

bool cmp2(node x,node y)
{
	return x.y<y.y;
}

bool cmp3(node x,node y)
{
	return x.num<y.num;
}

int main ()
{
	//freopen ("ii.txt","r",stdin);
	//freopen ("DD.txt","w",stdout);
	int i;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if (rhao[a[i].x]) 
			vr[rhao[a[i].x]].pb(mp(a[i].y,i));
		else
		{
			rhao[a[i].x]=++rt;
			vr[rt].pb(mp(a[i].y,i));
		}
		if (chao[a[i].y])
			vc[chao[a[i].y]].pb(mp(a[i].x,i));
		else
		{
			chao[a[i].y]=++ct;
			vc[ct].pb(mp(a[i].x,i));
		}
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp1);
	r[a[1].num].x=-1;r[a[1].num].y=a[2].x-a[1].x;
	r[a[n].num].x=a[n].x-a[n-1].x;r[a[n].num].y=-1;
	for (i=2;i<=n-1;i++)
		r[a[i].num]=mp(a[i].x-a[i-1].x,a[i+1].x-a[i].x);
	sort(a+1,a+n+1,cmp2);
	c[a[1].num]=mp(-1,a[2].y-a[1].y);
	c[a[n].num]=mp(a[n].y-a[n-1].y,-1);
	//for (i=1;i<=n;i++) cout<<r[i].x<<' '<<r[i].y<<"*"<<endl;
	//for (i=1;i<=n;i++) cout<<c[i].x<<' '<<c[i].y<<"#"<<endl;
	for (i=2;i<=n-1;i++)
		c[a[i].num]=mp(a[i].y-a[i-1].y,a[i+1].y-a[i].y);
	node2 ins;
	ins.num=a[1].num;
	if (r[a[1].num].x!=-1)
	{
		ins.s=true;
		ins.d=r[a[1].num].x;
		qr.push(ins);
	}
	if (r[a[1].num].y!=-1)
	{
		ins.s=false;
		ins.d=r[a[1].num].y;
		qr.push(ins);
	}
	if (c[a[1].num].x!=-1)
	{
		ins.s=true;
		ins.d=c[a[1].num].x;
		qc.push(ins);
	}
	if (c[a[1].num].y!=-1)
	{
		ins.s=false;
		ins.d=c[a[1].num].y;
		qc.push(ins);
	}
	m[a[1].num]=true;
	LL ans=0;
	int xx,yy,dd;node2 res;
	sort(a+1,a+n+1,cmp3);
	for (i=1;i<=n-1;i++)
	{
		do
		{
			res=qr.top();
			xx=res.s?a[res.num].x-res.d:a[res.num].x+res.d;
			while (vr[rhao[xx]].size()>0 && m[vr[rhao[xx]].back().y]) vr[rhao[xx]].pop_back();
			if (vr[rhao[xx]].size()==0) qr.pop();
		}
		while (vr[rhao[xx]].size()==0 && !qr.empty());
		do
		{
			res=qc.top();
			yy=res.s?a[res.num].y-res.d:a[res.num].y+res.d;
			while (vc[chao[yy]].size()>0 && m[vc[chao[yy]].back().y]) vc[chao[yy]].pop_back();
			if (vc[chao[yy]].size()==0) qc.pop();
		}
		while (vc[chao[yy]].size()==0 && !qr.empty());
		if (qc.empty() || qr.top().d<qc.top().d)
		{
			res=qr.top();qr.pop();
			xx=res.s?a[res.num].x-res.d:a[res.num].x+res.d;
			ans+=res.d;
			m[vr[rhao[xx]].back().y]=true;
			dd=vr[rhao[xx]].back().y;
			vr[rhao[xx]].pop_back();
			ins.num=dd;
			if (r[dd].x!=-1)
			{
				ins.s=true;
				ins.d=r[dd].x;
				qr.push(ins);
			}
			if (r[dd].y!=-1)
			{
				ins.s=false;
				ins.d=r[dd].y;
				qr.push(ins);
			}
			if (c[dd].x!=-1)
			{
				ins.s=true;
				ins.d=c[dd].x;
				qc.push(ins);
			}
			if (c[dd].y!=-1)
			{
				ins.s=false;
				ins.d=c[dd].y;
				qc.push(ins);
			}
		}
		else
		{
			res=qc.top();qc.pop();
			yy=res.s?a[res.num].y-res.d:a[res.num].y+res.d;
			ans+=res.d;
			m[vc[chao[yy]].back().y]=true;
			dd=vc[chao[yy]].back().y;
			vc[chao[yy]].pop_back();
			ins.num=dd;
			if (r[dd].x!=-1)
			{
				ins.s=true;
				ins.d=r[dd].x;
				qr.push(ins);
			}
			if (r[dd].y!=-1)
			{
				ins.s=false;
				ins.d=r[dd].y;
				qr.push(ins);
			}
			if (c[dd].x!=-1)
			{
				ins.s=true;
				ins.d=c[dd].x;
				qc.push(ins);
			}
			if (c[dd].y!=-1)
			{
				ins.s=false;
				ins.d=c[dd].y;
				qc.push(ins);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
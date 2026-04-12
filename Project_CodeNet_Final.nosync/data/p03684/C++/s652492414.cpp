#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define xxx 100100
using namespace std;
struct lian{
	int pre,nex;
}xx[xxx],yy[xxx];
struct haha{
	int p,w;
}tem;
struct cmp{
	bool operator()(haha &a,haha &b){
		return a.w>b.w;
	}
};
priority_queue<haha,vector<haha>,cmp>q;
struct node{
	int x,y,pos;
}p[xxx];
bool cmpxx(node p1,node p2)
{
	return p1.x<p2.x;
}
bool cmpyy(node p1,node p2)
{
	return p1.y<p2.y;
}
int n,used[xxx],ans;
bool cmppp(node p1,node p2)
{
	return p1.pos<p2.pos;
}

int dis(int u,int v)
{
	return min((int)abs(p[u].x-p[v].x),(int)abs(p[u].y-p[v].y));
}

void doxx(int pp)
{
	if (xx[pp].pre!=0) q.push((haha){xx[pp].pre,dis(pp,xx[pp].pre)});
	if (xx[pp].nex!=0) q.push((haha){xx[pp].nex,dis(pp,xx[pp].nex)});
	xx[xx[pp].nex].pre=xx[pp].pre;
	xx[xx[pp].pre].nex=xx[pp].nex;
}

void doyy(int pp)
{
	if (yy[pp].pre!=0) q.push((haha){yy[pp].pre,dis(pp,yy[pp].pre)});
	if (yy[pp].nex!=0) q.push((haha){yy[pp].nex,dis(pp,yy[pp].nex)});
	yy[yy[pp].nex].pre=yy[pp].pre;
	yy[yy[pp].pre].nex=yy[pp].nex;	
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
		p[i].pos=i;
	}
	sort(p+1,p+n+1,cmpxx);
	p[0].pos=p[n+1].pos=0;
	for (int i=1;i<=n;i++)
	{
		xx[p[i].pos].pre=p[i-1].pos;
		xx[p[i].pos].nex=p[i+1].pos;
	}
	sort(p+1,p+n+1,cmpyy);
	p[0].pos=p[n+1].pos=0;
	for (int i=1;i<=n;i++)
	{
		yy[p[i].pos].pre=p[i-1].pos;
		yy[p[i].pos].nex=p[i+1].pos;
	}
	sort(p+1,p+n+1,cmppp);
	ans=0;
	q.push((haha){1,0});
	while (!q.empty())
	{
		tem=q.top();
		q.pop();
		if (used[tem.p]) continue;
		ans+=tem.w;
		used[tem.p]=1;
		doxx(tem.p);
		doyy(tem.p);
	}
	cout<<ans<<endl;
	return 0;
}

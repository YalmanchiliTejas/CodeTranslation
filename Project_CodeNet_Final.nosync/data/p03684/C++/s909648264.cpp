#include<bits/stdc++.h>
using namespace std;
int f[100005];
int n;
int cnt;
struct house
{
	int x,y;
	int id;
};
house a[100005];
struct edge
{
	int x,y;
	int val;
};
edge e[100005<<2];
int find(int x)
{
	return x==f[x]? x : f[x]=find(f[x]);
}
bool cmp(house a,house b)
{
	return a.x<b.x;
}
bool cmp2(house a,house b)
{
	return a.y<b.y;
}
bool cmp3(edge a,edge b)
{
	return a.val<b.val;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		cnt++;
		e[cnt].x=a[i].id;
		e[cnt].y=a[i+1].id;
		e[cnt].val=abs(a[i].x-a[i+1].x);
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<n;i++)
	{
		cnt++;
		e[cnt].x=a[i].id;
		e[cnt].y=a[i+1].id;
		e[cnt].val=abs(a[i].y-a[i+1].y);
	}
	sort(e+1,e+cnt+1,cmp3);
	int p=0;
	long long ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int fx=find(e[i].x);
		int fy=find(e[i].y);
		if(fx==fy)
		{
			continue;
		}
		f[fx]=fy;
		ans+=e[i].val;
		p++;
		if(p==n-1)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
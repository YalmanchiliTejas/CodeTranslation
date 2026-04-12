#include<iostream>
#include<algorithm>
using namespace std;
#include<cstdio>
#include<cmath>
const int N=100005;
int n,f[N],k=0;
struct bian
{
	int u,v,w;
}
b[N*2];
struct node
{
	int x,y,self;
}
a[N];
int cmp1(node c,node d)
{
	return c.x<d.x;
}
int cmp2(node c,node d)
{
	return c.y<d.y;
}
int cmp3(bian c,bian d)
{
	return c.w<d.w;
}
void prepare()
{
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<n;i++)
	{
		k++;
		b[k].u=a[i].self;
		b[k].v=a[i+1].self;
		b[k].w=abs(a[i+1].x-a[i].x);
	}
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<n;i++)
	{
		k++;
		b[k].u=a[i].self;
		b[k].v=a[i+1].self;
		b[k].w=a[i+1].y-a[i].y;
	}
}
int ff(int x)
{
	if(f[x]==x)
	return x;
	if(f[x]!=x)
	return f[x]=ff(f[x]);
}
int kruskal()
{
	int ans=0;
	sort(b+1,b+k+1,cmp3);
	int t=0;
	for(int i=1;i<=k;i++)
	{
		int x1=ff(b[i].u);
		int x2=ff(b[i].v);
		if(x1!=x2)
		{
			ans+=b[i].w;
			f[x1]=x2;
			t++;
		}
		if(t==n-1)
		break;
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].self=i;
		f[i]=i;
	}
	prepare();
	cout<<kruskal();
}
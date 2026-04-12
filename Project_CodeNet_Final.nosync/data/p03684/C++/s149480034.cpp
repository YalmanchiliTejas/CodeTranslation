#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n;
int xx[N],yy[N];
int f[N];
int find(int x)
{
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
int p[N],q[N];
int cmp1(int x,int y)
{
	return xx[x]<xx[y];
}
int cmp2(int x,int y)
{
	return yy[x]<yy[y];
}
struct node
{
	int x,y,z;
	friend bool operator < (const node &aa,const node &bb)
	{
		return aa.z<bb.z;
	}
}ss[N*2];
int top;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&xx[i],&yy[i]);
		p[i]=i;q[i]=i;
	}
	sort(p+1,p+n+1,cmp1);sort(q+1,q+n+1,cmp2);
	for(int i=2;i<=n;i++)
	{
		ss[++top].x=p[i];ss[top].y=p[i-1];ss[top].z=xx[p[i]]-xx[p[i-1]];
		ss[++top].x=q[i];ss[top].y=q[i-1];ss[top].z=yy[q[i]]-yy[q[i-1]];
	}
	sort(ss+1,ss+top+1);
	int ans=0;
	for(int i=1;i<=top;i++)
	{
		int aa=find(ss[i].x),bb=find(ss[i].y);
		if(aa!=bb)
		{
			ans+=ss[i].z;
			f[aa]=bb;
		}
	}
	printf("%d\n",ans);
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
LL n,m,f[2010];
struct node{
	LL l,r,a;
}a[200010];
bool cmp(node a,node b) {return a.r<b.r;}
struct trnode{
	LL lc,rc,c,u;
}tr[400010];LL tot=0;
LL bt(LL l,LL r)
{
	LL x=++tot;
	if(l!=r)
	{
		LL mid=(l+r)/2;
		tr[x].lc=bt(l,mid);
		tr[x].rc=bt(mid+1,r);
	}
	return x;
}
void update(LL x)
{
	LL lc=tr[x].lc,rc=tr[x].rc,c=tr[x].u;
	tr[lc].c+=c;tr[rc].c+=c;
	tr[lc].u+=c;tr[rc].u+=c;
	tr[x].u=0;
}
void change(LL x,LL l,LL r,LL fl,LL fr,LL c)
{
	if(l==fl&&r==fr) {tr[x].c+=c;tr[x].u+=c;return;}
	LL mid=(l+r)/2;
	if(tr[x].u!=0) update(x);
	if(fr<=mid) change(tr[x].lc,l,mid,fl,fr,c);
	else if(fl>mid) change(tr[x].rc,mid+1,r,fl,fr,c);
	else change(tr[x].lc,l,mid,fl,mid,c),change(tr[x].rc,mid+1,r,mid+1,fr,c);
	tr[x].c=max(tr[tr[x].lc].c,tr[tr[x].rc].c);
}
LL findans(LL x,LL l,LL r,LL fl,LL fr)
{
	if(l==fl&&r==fr) return tr[x].c;
	LL mid=(l+r)/2;
	if(tr[x].u!=0) update(x);
	if(fr<=mid) return findans(tr[x].lc,l,mid,fl,fr);
	if(fl>mid) return findans(tr[x].rc,mid+1,r,fl,fr);
	return max(findans(tr[x].lc,l,mid,fl,mid),findans(tr[x].rc,mid+1,r,mid+1,fr));
}
int main()
{
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=m;i++) scanf("%lld %lld %lld",&a[i].l,&a[i].r,&a[i].a);
	sort(a+1,a+m+1,cmp);
	LL p=0;bt(0,n);
	for(LL i=1;i<=n;i++)
	{
		change(1,0,n,i,i,findans(1,0,n,0,i-1));
		while(p<m&&a[p+1].r==i) p++,change(1,0,n,a[p].l,a[p].r,a[p].a);
	}
	printf("%lld",findans(1,0,n,0,n));
}

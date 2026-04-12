#include <bits/stdc++.h>
using namespace std;
long long n,i,j,a[55],mx,s;
struct segment_tree
{
    long long l,r,sum,add;
    void update(long long x)
    {
        sum+=(r-l+1)*x;
        add+=x;
    }
}c[400005];
void pushdown(long long id)
{
    if (c[id].add)
    {
        c[id*2].update(c[id].add);
        c[id*2+1].update(c[id].add);
        c[id].add=0;
    }
}
void pushup(long long id)
{
    c[id].sum=c[id*2].sum+c[id*2+1].sum;
}
void build(long long id,long long l,long long r)
{
    c[id].l=l; 
	c[id].r=r;
    c[id].sum=0; 
	c[id].add=0;
    if(l==r) c[id].sum=a[l];
    else
    {
        long long mid=l+(r-l)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        pushup(id);
    }
}
void update(long long id,long long le,long long ri,long long x)
{
    if (le>c[id].r||ri<c[id].l) return;
    if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);
    else
    {
        pushdown(id);
        update(id*2,le,ri,x);
        update(id*2+1,le,ri,x);
        pushup(id);
    }
}
long long query(long long id,long long le,long long ri)
{
    if (ri<c[id].l||c[id].r<le) return 0;
    if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;
    long long ans=0;
    pushdown(id);
    ans+=query(id*2,le,ri);
    ans+=query(id*2+1,le,ri);
    pushup(id);
    return ans;
}
int main()
{
	cin>>n;for (i=1;i<=n;i++) cin>>a[i];build(1,1,n);
	for (;;)
	{
		//for (i=1;i<=n;i++) cerr<<query(1,i,i)<<' ';
		//cerr<<endl;
		mx=1;
		for (i=2;i<=n;i++)
		{
			if (query(1,i,i)>query(1,mx,mx)) mx=i;
		}
		if (query(1,mx,mx)<n) break;
		s+=(query(1,mx,mx)-(n-1)+n-1)/n;
		//cerr<<s<<endl;
		if (mx>1) update(1,1,mx-1,(query(1,mx,mx)-(n-1)+n-1)/n);
		if (mx<n) update(1,mx+1,n,(query(1,mx,mx)-(n-1)+n-1)/n);
		update(1,mx,mx,-((query(1,mx,mx)-(n-1)+n-1)/n*n));
	}
	cout<<s;
	return 0;
} 
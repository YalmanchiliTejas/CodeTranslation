#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int tr[N<<2],tag[N<<2],n,m,cnt=1;
void pushdown(int k)
{
	tr[k<<1]+=tag[k];
	tag[k<<1]+=tag[k];
	tr[k<<1|1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]+=v;
		tag[k]+=v;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
int query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
	else return max(query(k<<1,l,mid,a,mid),query(k<<1|1,mid+1,r,mid+1,b));
}
struct query
{
	int l,r,x;
	bool operator<(const query k)const
	{
		return r<k.r;
	}
}a[N];
main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i].l>>a[i].r>>a[i].x;
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++)
	{
		update(1,1,n,i,i,query(1,1,n,1,i));
		while(a[cnt].r==i)
		{
			update(1,1,n,a[cnt].l,a[cnt].r,a[cnt].x);
			cnt++;
		}
	}
	cout<<max(tr[1],0LL)<<endl;
	return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;
typedef long long ll;
const ll INF = 500000000000000;

int n,m,l[MAX_N],r[MAX_N],a[MAX_N];
ll tree[4*MAX_N],lazy[4*MAX_N];
int open[MAX_N],close[MAX_N];

void lazyupd(int i, int l, int r)
{
	if (lazy[i])
	{
		tree[i]+=lazy[i];
		if (l!=r)
			lazy[2*i]+=lazy[i],lazy[2*i+1]+=lazy[i];
		lazy[i]=0;
	}
}

void set(int i, int l, int r, int si, ll v)
{
	lazyupd(i,l,r);
	if (l==r)
	{
		tree[i]=v;
		return;
	}
	if ((l+r)/2>=si)
		set(2*i,l,(l+r)/2,si,v);
	else
		set(2*i+1,(l+r)/2+1,r,si,v);
	tree[i]=max(tree[2*i],tree[2*i+1]);
}

ll query(int i, int l, int r, int sr)
{
	lazyupd(i,l,r);
	if (l>sr)
		return -INF;
	if (r<=sr)
		return tree[i];
	return max(query(2*i,l,(l+r)/2,sr),query(2*i+1,(l+r)/2+1,r,sr));
}

void add(int i, int l, int r, int sr, int v)
{
	lazyupd(i,l,r);
	if (l>sr)
		return;
	if (r<=sr)
	{
		lazy[i]=v;
		lazyupd(i,l,r);
		return;
	}
	add(2*i,l,(l+r)/2,sr,v);
	add(2*i+1,(l+r)/2+1,r,sr,v);
	tree[i]=max(tree[2*i],tree[2*i+1]);
}
void add(int r, int v) { add(1,0,n,r,v); }

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d %d %d",l+i,r+i,a+i);
		open[i]=close[i]=i;
	}
	sort(open+1,open+1+m,[](const int &a, const int &b) {
		if (l[a]==l[b])
			return a<b;
		return l[a]<l[b];
	});
	sort(close+1,close+1+m,[](const int &a, const int &b) {
		if (r[a]==r[b])
			return a<b;
		return r[a]<r[b];
	});
	ll ans=0;
	int po=1,pc=1;
	for (int i=1; i<=n; i++)
	{
		for (;po<=m&&l[open[po]]==i; po++)
			add(l[open[po]]-1,a[open[po]]);
		for (;pc<=m&&r[close[pc]]==i-1; pc++)
			add(l[close[pc]]-1,-a[close[pc]]);
		ll h=query(1,0,n,i-1);
		ans=max(ans,h);
		set(1,0,n,i,h);
	}
	printf("%lld\n",ans);
	return 0;
}

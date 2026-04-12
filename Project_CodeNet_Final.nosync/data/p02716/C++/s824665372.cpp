#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
#define Mp make_pair
const int MAXN = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;

inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

struct Segment_Tree
{
	ll mx[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	inline void push_up(int u){ mx[u] = max(mx[ls(u)], mx[rs(u)]);}
	void update(int u,int l,int r,int q,ll k)
	{
		if(l==r){ mx[u]=k; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(ls(u),l,mid,q,k);
		else update(rs(u),mid+1,r,q,k);
		push_up(u);
	}
	ll query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return mx[u];
		int mid = (l+r)>>1;
		ll res=-linf;
		if(ql<=mid) chk_max(res, query(ls(u),l,mid, ql,qr));
		if(mid<qr) chk_max(res, query(rs(u),mid+1,r, ql,qr));
		return res;
	}
}tree;

ll a[MAXN];
ll pre[MAXN][2], suf[MAXN][2];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	if(!(n&1)) a[++n]=-1e16;
	
	for(int i=1; i<=n; ++i)
	{
		pre[i][0] = pre[i-1][0];
		pre[i][1] = pre[i-1][1];
		pre[i][i&1] += a[i];
	}
	for(int i=n; i>=1; --i)
	{
		suf[i][0] = suf[i+1][0];
		suf[i][1] = suf[i+1][1];
		suf[i][i&1] += a[i];
	}
	
	ll ans=-linf, dif=0;
	for(int i=1; i<=n; ++i)
	{
		if(i>1) chk_max(ans, suf[i+1][1] + tree.query(1,1,n, 1,i-1) + dif);
		if(!(i&1)) dif += a[i];
		tree.update(1,1,n, i,pre[i-1][1]-dif);
	}
	printf("%lld",ans);
	return 0;
}
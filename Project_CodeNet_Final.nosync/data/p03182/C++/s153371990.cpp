#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ff first 
#define ss second
#define mod 1000000007
#define INF 1000000007
#define lim 200005
#define nfs_mw ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

//problem based
struct node{
	int l,r; ll mim,lazy;
	void reset(int l = 0, int r = 0, ll mim = 0, ll lazy = 0)	{ this->mim=mim; this->l=l; this->r=r; this->lazy = lazy; }
};
vector<node> segTree(4*lim);

//problem based
void merge(node& f,node j,node k)
{
	f.reset(j.l,k.r,max(j.mim+j.lazy,k.mim+k.lazy));
}

void merge(int i)
{
	merge(segTree[i],segTree[2*i],segTree[2*i+1]);
}

void build(int l,int r,int i = 1)
{
	if(l==r) { segTree[i].reset(l,l); return; }
	int m = (l+r)/2;
	build(l,m,2*i);
	build(m+1,r,2*i+1);
	merge(i);
}

//problem based
inline void update_lazy(ll val,node &d) { d.lazy += val; }

//problem based
inline void update_lazy(node &a,node &b) { update_lazy(a.lazy,b); }

//problem based
inline bool check_lazy(node &a){ return a.lazy; }

void push(int i)
{
	update_lazy(segTree[i],segTree[2*i]);
	update_lazy(segTree[i],segTree[2*i+1]);
	merge(i);
}

// minorly problem based (function arguments and stuff)
void range_update(ll val,int l,int r,int i=1)
{
	node &a = segTree[i];
	if(r<a.l || l>a.r) return;
	if(a.l>=l && a.r<=r) { update_lazy(val,a); return; }
	if(check_lazy(a)) push(i);
	range_update(val,l,r,2*i); range_update(val,l,r,2*i+1);
	merge(i);
}

void update_no(ll val, int l, int i=1)
{
	node &a=segTree[i];
	if(a.l==a.r){ a.reset(l,l,val); return; }
	update_no(val,l,2*i+(l>(a.l+a.r)/2));
	merge(i);
}

// problem based (use merge smartly or write your own).
inline void take(int i) { merge(segTree[0],segTree[0],segTree[i]); }

void query(int l,int r,int i=1)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l >= l && a.r <= r) { take(i); return; }
	if(check_lazy(a)) push(i);
	query(l,r,2*i); query(l,r,2*i+1);
}

//problem based
ll act_query(int l,int r)
{
	segTree[0].reset(-INF,-1,-1e18,0);
	query(l,r);
	return segTree[0].mim;
}

int main()
{
	nfs_mw;
	ll ans = 0;
	int i,j,k,n,m,l[lim],r[lim]; ll a[lim];
	cin>>n>>m;
	vector<pair<int,int>> open,close;
	for(i=0; i<m; i++){
		cin>>l[i]>>r[i]>>a[i];
		open.pb(mp(l[i],i));
		close.pb(mp(r[i],i));
	}
	sort(open.begin(), open.end());
	sort(close.begin(), close.end());
	build(0,n);
	for(i=1,j=0,k=0; i<=n; i++){
		for(; j<m && open[j].ff == i; j++) 
			range_update(a[open[j].ss],0,l[open[j].ss]-1);
		ll v = act_query(0,i-1);
		ans = max(ans,v);
		update_no(v,i);
		for(; k<m && close[k].ff == i; k++) 
			range_update(-a[close[k].ss],0,l[close[k].ss]-1);
	}
	cout<<ans;
}



// //problem based
// int query_bs(int val = 0, int i = 1) // returns rightmost position with value < val, -1 if it does not exist.
// {
// 	node &a = segTree[i]; int ret;
// 	if(a.mim + a.lazy >= val) return -1;
// 	if(a.l == a.r) return a.r;
// 	if(check_lazy(a)) push(i);
// 	return ((ret = query_bs(val,2*i+1)) != -1)?ret:query_bs(val,2*i);	
// }
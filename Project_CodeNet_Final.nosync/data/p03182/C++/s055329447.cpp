#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

map<ii,ll> ma;

bool cmp(pair<ii,ll> a, pair<ii,ll> b)
{
	if(a.fi.fi!=b.fi.fi) return (a.fi.fi<b.fi.fi);
	if(a.fi.se!=b.fi.se) return (a.fi.se>b.fi.se);
	return (a.se<b.se);
}


class LazySegmentTree {
private:
	int size_;
	vector<long long> v, lazy;
	void update(int a, int b, long long x, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] += x;
			push(k, l, r);
		}
		else {
			update(a, b, x, k * 2, l, (l + r) >> 1);
			update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
			v[k] = merge(v[k * 2], v[k * 2 + 1]);
		}
	}
	long long query(int a, int b, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return v[k];
		long long lc = query(a, b, k * 2, l, (l + r) >> 1);
		long long rc = query(a, b, k * 2 + 1, (l + r) >> 1, r);
		return merge(lc, rc);
	}
 
public:
	LazySegmentTree() : v(vector<long long>()), lazy(vector<long long>()) {};
	LazySegmentTree(int n) {
		for (size_ = 1; size_ < n;) size_ <<= 1;
		v.resize(size_ * 4,0);
		lazy.resize(size_ * 4,0);
	}
	inline void push(int k, int l, int r) {
		if (lazy[k] != 0) {
			v[k] += lazy[k];
			if (r - l > 1) {
				lazy[k * 2] += lazy[k];
				lazy[k * 2 + 1] += lazy[k];
			}
			lazy[k] = 0;
		}
	}
	inline long long merge(long long x, long long y) {
		return min(x,y);
	}
	inline void update(int l, int r, long long x) {
		update(l, r, x, 1, 0, size_);
	}
	inline long long query(int l, int r) {
		return query(l, r, 1, 0, size_);
	}
};

vector<ii> V[222222];
ll dp[222222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m; ll sum=0;
	for(int i=0;i<m;i++)
	{
		int l,r; ll w; cin>>l>>r>>w;
		ma[mp(l,r)]+=w; sum+=w;
	}
	vector<pair<ii,ll> > vec;
	for(auto X:ma)
	{
		vec.pb(X);
	}
	sort(vec.begin(),vec.end(),cmp);
	for(auto X:vec)
	{
		V[X.fi.se].pb(mp(X.fi.fi,X.se));
	}
	LazySegmentTree st(n+5);
	for(int i=1;i<=n+1;i++)
	{
		dp[i] = st.query(0,i);
		//cerr<<i<<' '<<dp[i]<<'\n';
		for(ii v:V[i])
		{
			st.update(0,v.fi,v.se);
		}
		st.update(i,i+1,dp[i]);
	}
	cout<<sum-dp[n+1]<<'\n';
}

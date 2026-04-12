#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
#define endl '\n'
#define F first
#define S second
const int MAX_N=2e5+5;

int n,m;
vector<int> intervals[MAX_N];
ll a[MAX_N];
struct Node
{
	ll data, tag;
	Node operator += (const ll &x)
	{
		data+=x;
		tag+=x;
		return (*this);
	}
	ll operator () () const
	{ return data; }
	void down(Node &l, Node &r)
	{
		l+=tag;
		r+=tag;
		tag=0;
	}
	void up(Node &l, Node &r)
	{
		data=max(l.data, r.data);
	}
};
struct ST
{
	Node a[4*MAX_N];
	void up(int idx)
	{}
	void mod(int L, int R, int l, int r, ll d, int idx=1)
	{
		if(R<l||r<L) return;
		if(l!=r) a[idx].down(a[idx<<1], a[idx<<1|1]);
		if(L<=l&&r<=R)
		{
			a[idx]+=d;
			return;
		}
		int mid=(l+r)/2;
		mod(L, R, l, mid, d, idx<<1);
		mod(L, R, mid+1, r, d, idx<<1|1);
		a[idx].up(a[idx<<1], a[idx<<1|1]);
	}
	ll query(int L, int R, int l, int r, int idx=1)
	{
		if(R<l||r<L) return LLONG_MIN;
		if(l!=r) a[idx].down(a[idx<<1], a[idx<<1|1]);
		if(L<=l&&r<=R) return a[idx]();
		int mid=(l+r)/2;
		return max(query(L, R, l, mid, idx<<1), query(L, R, mid+1, r, idx<<1|1));
	}
} st;
int l[MAX_N], r[MAX_N];
ll ans;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&l[i],&r[i],&a[i]);
		intervals[l[i]].emplace_back(i);
		intervals[r[i]+1].emplace_back(-i);
	}
	n++;
	for(int i=1;i<=n;i++)
	{
		for(auto &j:intervals[i])
		{
			if(j>0) st.mod(1, n, 1, n, a[j]);
			else
			{
				st.mod(1, l[-j]-1, 1, n, -a[-j]);
				st.mod(r[-j]+1, n, 1, n, -a[-j]);
			}
		}
		ll tmp=st.query(1, n, 1, n);
		ans=max(ans, tmp);
		ll t2=st.query(i, i, 1, n);
		st.mod(i, i, 1, n, -t2+tmp);
	}
	printf("%lld\n", ans);
	return 0;
}


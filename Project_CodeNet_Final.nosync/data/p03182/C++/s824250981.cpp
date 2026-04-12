#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
#define mp make_pair
#define N 201000
#define ll long long

ll n,m,l,r,x;
vector<pii> a[N],b[N];
ll dp[N],tag[N<<2],mx[N<<2],ans;

void pd(ll o) {
	ll ls=o<<1,rs=o<<1|1;
	tag[ls]+=tag[o]; tag[rs]+=tag[o];
	mx[ls]+=tag[o]; mx[rs]+=tag[o];
	tag[o]=0;
}

void upd(ll o,ll L,ll R,ll l,ll r,ll x) {
	if (l<=L && r>=R) {
		tag[o]+=x; mx[o]+=x;
		return;
	}
	pd(o);
	ll mid=(L+R)>>1;
	if (l<=mid) upd(o<<1,L,mid,l,r,x);
	if (r>mid) upd(o<<1|1,mid+1,R,l,r,x);
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}

ll query(ll o,ll L,ll R,ll l,ll r) {
	if (l<=L && r>=R) return mx[o];
	pd(o);
	ll mid=(L+R)>>1;
	ll ret=-1000000000000000ll;
	if (l<=mid) ret=max(ret,query(o<<1,L,mid,l,r));
	if (r>mid) ret=max(ret,query(o<<1|1,mid+1,R,l,r));
	return ret;
}

int main()
{
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=m;i++) {
		scanf("%lld%lld%lld",&l,&r,&x);
		a[l].push_back(mp(l-1,x));
		b[r].push_back(mp(l-1,x));
	}
	dp[0]=0;
	for (ll i=1;i<=n;i++) {
		for (auto t:a[i]) upd(1,0,n,0,t.first,t.second);
		dp[i]=query(1,0,n,0,i-1);
		upd(1,0,n,i,i,dp[i]);
		ans=max(ans,dp[i]);
		//printf("%lld\n",dp[i]);
		for (auto t:b[i]) upd(1,0,n,0,t.first,-t.second); 
	}
	printf("%lld\n",ans);
	return 0;
}
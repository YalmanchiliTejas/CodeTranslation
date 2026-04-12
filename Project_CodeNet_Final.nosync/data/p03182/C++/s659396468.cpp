#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mp make_pair
#define int ll
const int N=2e5+5;
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		ch=getchar();
		if (ch=='-') w=-1;	
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
priority_queue<ll>q;
vector<pr>g[N];
int n,m;
ll ans,a[N],dp[N],p[N];
namespace bit{
	#define lowbit(i) (i&(-i))
	ll s[N];
	inline void Add(int x,int k){
		for (int i=x;i<=n;i+=lowbit(i))
			s[i]+=k;
	}
	inline ll sum(int x){
		ll res=0;
		for (int i=x;i;i-=lowbit(i))
			res+=s[i];
		return res;
	}
}
using namespace bit;
namespace seg{
	#define ls (x<<1)
	#define rs (ls|1)
	#define mid (l+r>>1)
	ll mx[N<<2],add[N<<2];
	inline void pushup(int x){
		mx[x]=max(mx[ls],mx[rs]);
	}
	inline void pushdown(int x){
		if (!add[x]) return;
		mx[ls]+=add[x],mx[rs]+=add[x];
		add[ls]+=add[x],add[rs]+=add[x];
		add[x]=0;
	}
	void update(int x,int l,int r,int L,int R,int k){
		if (L<=l && r<=R){
			add[x]+=k,mx[x]+=k;
			return;
		}
		pushdown(x);
		if (L<=mid) update(ls,l,mid,L,R,k);
		if (R>mid) update(rs,mid+1,r,L,R,k);
		pushup(x);
	}
	ll query(int x,int l,int r,int L,int R){
		if (L>R) return 0;
		if (L<=l && r<=R) return mx[x];
		ll res=0;
		pushdown(x);
		if (L<=mid) res=max(res,query(ls,l,mid,L,R));
		if (R>mid) res=max(res,query(rs,mid+1,r,L,R));
		return res;
	}
}
using namespace seg;
signed main(){
	n=read(),m=read();
	for (int i=1;i<=m;++i){
		int l=read(),r=read(),w=read();
		Add(l,w),Add(r+1,-w);
		g[r].push_back(mp(l,w));
	}
	for (int i=1;i<=n;++i) a[i]=sum(i);
	for (int i=1;i<=n;++i){
		ll S=0;
		for (int j=0,sz=g[i-1].size();j<sz;++j){
			int l=g[i-1][j].first,w=g[i-1][j].second;
			if (l<=i-2) update(1,1,n,l,i-2,w);
			S+=w;
		}
		if (i!=1) update(1,1,n,i-1,i-1,S-a[i-1]);
		dp[i]=query(1,1,n,1,i-1)+a[i];
		update(1,1,n,i,i,dp[i]);
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
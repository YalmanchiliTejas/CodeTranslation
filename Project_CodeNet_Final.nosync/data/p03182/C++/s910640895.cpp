/* --- author: dxm --- */
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}

const int maxn=200005;
int n,m;
vector<pll>val[maxn];
ll f[maxn],g[maxn];

namespace Segtree{
	ll t[maxn*4],tag[maxn*4];
	void pushdown(int v){
		if(tag[v]){
			t[v<<1]+=tag[v];
			t[v<<1|1]+=tag[v];
			tag[v<<1]+=tag[v];
			tag[v<<1|1]+=tag[v];
			tag[v]=0;
		}
	}
	void update(int v,int l,int r,int vl,int vr,ll val){
		if(vl>vr)return;
		if(l>=vl&&r<=vr){
			t[v]+=val;
			tag[v]+=val;
			return;
		}
		pushdown(v);
		int mid=(l+r)>>1;
		if(mid>=vl)update(v<<1,l,mid,vl,vr,val);
		if(mid<vr)update(v<<1|1,mid+1,r,vl,vr,val);
		t[v]=max(t[v<<1],t[v<<1|1]);
	}
	ll query(int v,int l,int r,int vl,int vr){
		if(vl>vr)return -Inf;
		if(l>=vl&&r<=vr)return t[v];
		pushdown(v);
		int mid=(l+r)>>1;
		ll sl=mid>=vl?query(v<<1,l,mid,vl,vr):-Inf;
		ll sr=mid<vr?query(v<<1|1,mid+1,r,vl,vr):-Inf;
		return max(sl,sr);
	}
}

int main(){
#ifdef FILE
	freopen("FILE.in","r",stdin);
	freopen("FILE.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	REP(i,m){
		int l,r,a;
		scanf("%d%d%d",&l,&r,&a);
		val[r].pb(mp(l,a));
	}
	REP(i,n){
		ll sum=0;
		rep(j,val[i].size()){
			Segtree::update(1,1,n,val[i][j].fst,i-1,val[i][j].snd);
			sum+=val[i][j].snd;
		}
		f[i]=g[i-1]+sum;
		g[i]=max(max(g[i-1]+sum,0LL),Segtree::query(1,1,n,1,i-1));
		Segtree::update(1,1,n,i,i,f[i]);
	}
	printf("%lld\n",g[n]);
#ifdef TIME
	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
#endif
	return 0;
}

/*
Input:
-----------------
Output:
*/

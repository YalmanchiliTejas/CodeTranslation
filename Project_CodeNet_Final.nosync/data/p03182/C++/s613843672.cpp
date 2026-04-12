/*----------------by syr----------------*/
/*
  -----  -----  -----
  |   |  |---|    _/
  |   |  | \_    /
  -----  |   \  -----

  |---\  \   /  |\  /|
  |   |   \_/   | \/ |
  |   |   / \   |    |
  |---/  /   \  |    |
*/
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;

const int INF=1e9+7;
const int maxn=2e5+5;

class SegmentTree{
private:
	int sz;
	ll dat[maxn<<2],add[maxn<<2];
	inline void pushDown(int x){
		add[x<<1]+=add[x];
		add[x<<1|1]+=add[x];
		dat[x<<1]+=add[x];
		dat[x<<1|1]+=add[x];
		add[x]=0;
		return;
	}
public:
	SegmentTree(){}
	inline int size(){return sz;}
	inline void init(int n){
		for(sz=1;sz<n;sz<<=1);
		memset(dat,0,sizeof(dat));
		memset(add,0,sizeof(add));
		return;
	}
	inline void update(int x,int l,int r,int s,int t,ll k){
//		if(x==1) printf("update: %d %d %lld\n",s,t,k);
		if(l>t||r<s) return;
		if(l>=s&&r<=t){
//			printf("x=%d dat[x]=%lld k=%lld\n",x,dat[x],k);
			dat[x]+=k;
			add[x]+=k;
			return;
		}
		int md=(l+r)>>1;
		pushDown(x);
		update(x<<1,l,md,s,t,k);
		update(x<<1|1,md+1,r,s,t,k);
		dat[x]=max(dat[x<<1],dat[x<<1|1]);
		return;
	}
	inline ll query(int x,int l,int r,int s,int t){
		if(l>t||r<s) return 0;
		if(l>=s&&r<=t) return dat[x];
		int md=(l+r)>>1;
		pushDown(x);
		ll vl=query(x<<1,l,md,s,t);
		ll vr=query(x<<1|1,md+1,r,s,t);
		return max(vl,vr);
	}
	inline void print(int x,int l,int r){
//		printf("x=%d l=%d r=%d dat=%lld add=%lld\n",x,l,r,dat[x],add[x]);
		if(l==r) return;
		int md=(l+r)>>1;
		print(x<<1,l,md);
		print(x<<1|1,md+1,r);
		return;
	}
}seg;

int n,m;
ll dp[maxn],sum[maxn];
vector<pii> cov[maxn];

int main(){
	scanf("%d%d",&n,&m);
	seg.init(n+1);
	FOR(i,0,m){
		int l,r,w;
		scanf("%d%d%d",&l,&r,&w);
		cov[r].PB(MP(l,w));
		seg.update(1,0,seg.size()-1,l,r,-w);
		sum[l]+=w;sum[r+1]-=w;
	}
	REP(i,1,n+1) sum[i]+=sum[i-1];
	REP(i,1,n){
//		seg.print(1,0,seg.size()-1);
		dp[i]=seg.query(1,0,seg.size()-1,0,i-1)+sum[i];
		FOR(j,0,cov[i].size()){
			seg.update(1,0,seg.size()-1,cov[i][j].fst,i,cov[i][j].snd);
//			seg.print(1,0,seg.size()-1);
		}
		seg.update(1,0,seg.size()-1,i,i,dp[i]);
//		printf("sum[%d]=%lld dp[%d]=%lld\n",i,sum[i],i,dp[i]);
	}
	printf("%lld\n",seg.query(1,0,seg.size()-1,0,n));
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 2e5 + 5;

class SegmentTree{
private:
	int sz;
	ll dat[maxn << 2], add[maxn << 2];
	inline void pushDown(int x){
		add[x << 1] += add[x];
		add[x << 1 | 1] += add[x];
		dat[x << 1] += add[x];
		dat[x << 1 | 1] += add[x];
		add[x] = 0;
		return;
	}
public:
	SegmentTree(){}
	inline int size(){ return sz; }
	inline void init(int n){
		for(sz = 1; sz < n; sz <<= 1);
		memset(dat, 0, sizeof(dat));
		memset(add, 0, sizeof(add));
		return;
	}
	inline void update(int x,int l,int r,int s,int t,ll k){
		if(l > t || r < s) return;
		if(l >= s && r <= t){
			dat[x] += k;
			add[x] += k;
			return;
		}
		int md=(l + r) >> 1;
		pushDown(x);
		update(x << 1, l, md, s, t, k);
		update(x << 1 | 1, md + 1, r, s, t, k);
		dat[x] = max(dat[x << 1], dat[x << 1 | 1]);
		return;
	}
	inline ll query(int x,int l,int r,int s,int t){
		if(l > t || r < s) return 0;
		if(l >= s && r <= t) return dat[x];
		int md=(l + r) >> 1;
		pushDown(x);
		ll vl = query(x << 1,l, md, s, t);
		ll vr = query(x << 1 | 1, md + 1, r, s, t);
		return max(vl, vr);
	}
	inline void print(int x,int l,int r){
		if(l == r) return;
		int md= l + r >> 1;
		print(x << 1, l, md);
		print(x << 1 | 1, md+1, r);
		return;
	}
}seg;

int n,m;
ll dp[maxn],sum[maxn];
vector<pii> cov[maxn];

int main(){
	scanf("%d%d", &n, &m);
	seg.init(n+1);
	FOR(i,0,m){
		int l,r,w;
		scanf("%d%d%d",  &l, &r, &w);
		cov[r].PB(MP(l, w));
		seg.update(1, 0, seg.size() - 1, l, r, -w);
		sum[l] += w;
		sum[r + 1] -= w;
	}
	REP(i, 1, n + 1) sum[i] += sum[i - 1];
	REP(i, 1, n){
		dp[i] = seg.query(1, 0, seg.size() - 1, 0, i - 1) + sum[i];
		FOR(j, 0, cov[i].size()){
			seg.update(1, 0, seg.size() - 1, cov[i][j].fst, i, cov[i][j].snd);
		}
		seg.update(1, 0, seg.size()-1, i, i, dp[i]);
	}
	printf("%lld\n",seg.query(1, 0, seg.size()-1, 0, n));
	return 0;
}

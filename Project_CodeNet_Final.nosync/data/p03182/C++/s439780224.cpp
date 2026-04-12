#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);

struct LazySegmentTree {
private:
	int n;
	vector<ll> node, lazy;
public:
	LazySegmentTree(vector<ll> v) {
		int sz = (int)v.size();
		n = 1; while(n < sz) n *= 2;
		node.resize(2*n-1,INF);
		lazy.resize(2*n-1,0);
		for(int i=0; i<sz; i++) node[i+n-1] = v[i];
		for(int i=n-2;i>=0;i--) node[i] = min(node[i*2+1] , node[i*2+2]);
	}
	void eval(int k, int l, int r) {
		if(lazy[k] != 0) {
			node[k] += lazy[k];
			if(r - l > 1) {
				if(node[2*k+1]!=INF)lazy[2*k+1] += lazy[k];
				if(node[2*k+2]!=INF)lazy[2*k+2] += lazy[k];
			}
			lazy[k] = 0;
		}
	}
	void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
		if(r < 0) r = n;
		eval(k, l, r);
		if(b <= l || r <= a) return;
		if(a <= l && r <= b) {
			lazy[k] += x;
			eval(k, l, r);
		}
		else {
			add(a, b, x, 2*k+1, l, (l+r)/2);
			add(a, b, x, 2*k+2, (l+r)/2, r);
			node[k] = min(node[2*k+1] , node[2*k+2]);
		}
	}
	ll getmin(int a, int b, int k=0, int l=0, int r=-1) {
		if(r < 0) r = n;
		if(b <= l || r <= a) return INF;
		eval(k, l, r);
		if(a <= l && r <= b) return node[k];
		ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
		ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
		return min(vl , vr);
	}
};

int main(){
	ll N,M,ans=0,l,r,a;
	cin >> N >> M;
	LazySegmentTree dp( vector<ll>(N+1,0) );
	vector< vector<P> > add(N+2),del(N+2);
	FOR(i,0,M){
		cin >> l >> r >> a;
		add[l].push_back({l,-a});
		del[r].push_back({l,-a});
	}

	FOR(i,1,N+1){
		for(auto x:add[i]){
			dp.add(0,i,x.second);
		}
		a = dp.getmin(0,i);
		ans = min(ans,a);
		dp.add(i,i+1,a);
		for(auto x:del[i]){
			dp.add(0,x.first,-x.second);
		}
	}
	cout << -ans << endl;
}


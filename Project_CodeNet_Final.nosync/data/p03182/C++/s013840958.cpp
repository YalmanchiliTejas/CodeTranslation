#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define ri2(x,y) scanf("%d %d",&(x),&(y))
#define ri3(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define rll(x) scanf("%lld",&(x))
#define rll2(x,y) scanf("%lld %lld",&(x),&(y))
#define rll3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z))
#define gc(x) ((x) = getchar())
using namespace::std;

const long double PI = acos(-1);
const long long MOD = 1000000000 +7;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> tll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<tll> vtll;
typedef vector<string> vs;
typedef set<int> si;
typedef set<ii> sii;
typedef set<iii> siii;

ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b);}

ll add(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a+b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}

ll mul(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a*b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}

ll pow_mod(ll a, ll b, ll m = MOD){
	ll res = 1LL;
	a = a%m;
	while(b){
		if(b&1) res = mul(res,a,m);
		b >>= 1;
		a = mul(a,a,m);
	}
	return res;
}

ll fastexp(ll a, ll b){
	ll res = 1LL;
	while(b){
		if(b&1) res = res*a;
		b >>= 1;
		a *= a;
	}
	return res;
}

int gcdExtendido(int a, int b, int *x, int *y){
	if(a == 0){
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtendido(b%a,a,&x1,&y1);
	
	*x = y1-(b/a)*x1;
	*y = x1;
	return gcd;
}

int modInverso(int a, int m){
	int x, y;
	int g = gcdExtendido(a,m,&x,&y);
	if(g!=1) return -1;
	else return (x%m + m)%m;
}

/****************************************
*************P*L*A*N*T*I*L*L*A************
*****************************************/

const int N = 200000+5;
const ll inf = 1LL<<50;

struct SegTree{
	int n;
	vector<long long> st;
	vector<long long> lazy;

	SegTree(int n) :
		n(n), st(4 * n, inf), lazy(4 * n, 0LL) {}


	void push(int pos, int l, int r){
		if(lazy[pos]){
			st[pos] += lazy[pos];
			if(l < r){
				lazy[2*pos] += lazy[pos];
				lazy[2*pos+1] += lazy[pos];
			}
			lazy[pos] = 0;
		}
	}

	void update(int x, int y, long long z, int pos, int l, int r){
		push(pos,l,r);
		if(y < l or r < x or x > y) return;
		if(x <= l and r <= y){
			lazy[pos] += z;
			push(pos,l,r);
			return;
		}
		int mi = (l+r) / 2;
		update(x,y,z,2*pos,l,mi);
		update(x,y,z,2*pos+1,mi+1,r);
		st[pos] = min(st[2*pos], st[2*pos+1]);
	}

	void update(int x, int y, long long z){
		update(x, y, z, 1, 0, n-1);
	}

	long long query(int x, int y, int pos, int l, int r){
		push(pos,l,r);
		if(y < l or r < x or x > y) return 0LL;
		if(x <= l and r <= y) return st[pos];
		int mi = (l+r) / 2;
		return min(query(x,y,2*pos,l,mi), query(x,y,2*pos+1,mi+1,r));
	}

	long long query(int x, int y){
		return query(x, y, 1, 0, n-1);
	}
};

int n, m;
vii intervals[N];

int main(){
	ri2(m,n);
	ll sum = 0LL;
	for(int i=1; i<=n; i++){
		int l, r, a;
		ri3(l,r,a);
		intervals[r].emplace_back(mp(l, a));
		sum += a;
	}
	ll ans = LLONG_MAX;
	SegTree S(m + 1);
	S.update(0, 0, -inf);
	for(int i=1; i<=m+1; i++){
		for(ii e : intervals[i-1]){
			S.update(0, e.first-1, e.second);
		}
		ll cur = S.query(0, m);
		S.update(i, i, cur - inf);
	}
	printf("%lld\n",sum - S.query(0,m));
	return 0;
}
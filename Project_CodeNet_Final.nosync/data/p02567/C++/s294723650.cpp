#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include <complex>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 1020000;
ll dy[8] = {1,-1,0,0,1,-1,1,-1};
ll dx[8] = {0,0,1,-1,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T> inline void print(T &a){
    for(auto itr = a.begin(); itr != a.end(); itr++){
		cout << *itr << " ";
	}
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){
	cout << "debug: " << a << " " << b << "\n";
}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << "debug: " << a << " " << b << " " << c << "\n";
}
void mark() {cout << "#" << "\n";}
ll pcount(ll x) {return __builtin_popcountll(x);}
const int mod = 1e9 + 7;
//const int mod = 998244353;

template<typename Monoid>
struct Segtree {
	using F = function<Monoid(Monoid, Monoid)>;
	int sz;
	vector<Monoid> seg;
	const F f;
	const Monoid M;

	Segtree(int n, const F f, const Monoid &M) : f(f), M(M){
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, M);
	}

	void set(int k, const Monoid &x) {
		seg[k + sz] = x;
	}

	void build(){
		for(int k=sz-1; k>0; k--){
			seg[k] = f(seg[2*k], seg[2*k+1]);
		}
	}

	void update(int k, const Monoid &x){
		k += sz;
		seg[k] = x;
		while(k >>= 1){
			seg[k] = f(seg[2*k], seg[2*k+1]);
		}
	}

	Monoid query(int a, int b){
		Monoid L = M, R = M;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1){
			if(a & 1) L = f(L, seg[a++]);
			if(b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}

	Monoid operator[](const int &k) const {
		return seg[k + sz];
	}

	template<typename C>
	int find_subtree(int a, const C &check, Monoid &M0, bool type){
		while(a < sz){
			Monoid nxt = type ? f(seg[2*a]+type,M0) : f(M0,seg[2*a]+type);
			if(check(nxt)) a = 2 * a + type;
			else M0 = nxt, a = 2 * a + 1 - type;
		}
		return a - sz;
	}

	template<typename C>
	int find_first(int a, const C &check){
		Monoid L = M;
		if(a <= 0){
			if(check(f(L, seg[1]))) return find_subtree(1,check,L,false);
			return -1;
		}
		int b = sz;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1){
			if(a & 1){
				Monoid nxt = f(L, seg[a]);
				if(check(nxt)) return find_subtree(a,L,check,false);
				L = nxt;
				++a;
			}
		}
		return -1;
	}

	template<typename C>
	int find_last(int b, const C &check){
		Monoid R = M;
		if(b >= sz){
			if(check(f(seg[1], R))) return find_subtree(1,check,R,true);
			return -1;
		}
		int a = sz;
		for(b += sz; a < b; a >>= 1, b >>= 1){
			if(b & 1){
				Monoid nxt = f(seg[--b], R);
				if(check(nxt)) return find_subtree(b,check,R,true);
				R = nxt;
			}
		}
		return -1;
	}
};

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n,q; cin >> n >> q;
	vl a(n); rep(i,n) cin >> a[i];
	Segtree<ll> seg(n,[](ll a, ll b){return max(a,b);},0);
	rep(i,n) seg.set(i,a[i]);
	seg.build();
	while(q--){
		int t,a,b; cin >> t >> a >> b;
		a--;
		if(t == 1){
			seg.update(a,b);
		}
		if(t == 2){
			cout << seg.query(a,b) << "\n";
		}
		if(t == 3){
			int ok = n+1, ng = a;
			while(ok-ng > 1){
				ll mid = (ok+ng) / 2;
				if(seg.query(a,mid) >= b) ok = mid;
				else ng = mid;
			}
			cout << ok << "\n";
		}
	}
}
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <utility>
#include <memory>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <forward_list>

#define cauto const auto&
#else

#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll;
typedef vector<vector<long long> > vvll;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _rep(i,n) _rep2((i),0,(n))
#define _rep2(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) GET_MACRO(__VA_ARGS__, _rep2, _rep)(__VA_ARGS__)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define fi first
#define se second
#define mkp make_pair
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

class UF {
	public:
	static const int ufmax=100052;
	int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
	UF() { init();}
	void init(){int i; rep(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
	int find(int x) {	return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
	int operator[](int x) {return find(x);}
	int count(int x) {return ufcnt[find(x)];}
	void unite(int x,int y) {
		x = find(x); y = find(y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};
UF uf;
VV(pii) vv;
vint d;
vector<pii> p;


void dfs(int x, int dd = 0, int par = -1){
	d[x] = dd;
	for(pii y: vv[x]){
		if(par == y.fi) continue;
		dfs(y.fi, dd+1, x);
		p[y.fi] = pii(x,y.se);
	}
}

void mainmain(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,pii>> v(m);
	rep(i,m){
		cin>>v[i].se.fi>>v[i].se.se>>v[i].fi;
	}
	vv = VV(pii)(n);
	sort(ALL(v));
	ll ans = 0;
	rep(i,m){
		int a = v[i].se.fi;
		int b = v[i].se.se;
		a--,b--;
		if(uf[a] == uf[b]) continue;
		uf.unite(a,b);
		vv[a].PB(pii(b,v[i].fi));
		vv[b].PB(pii(a,v[i].fi));
		ans += v[i].fi;
	}
	d = vint(n);
	p = vector<pii>(n);
	dfs(0);
	int Q;
	cin>>Q;
	rep(_,Q){
		int s,t;
		cin>>s>>t;
		s--,t--;
		int tmp = 0;
		while(s!=t){
			if(d[s]>d[t]){
				maxs(tmp, p[s].se);
				s = p[s].fi;
			}
			else{
				maxs(tmp, p[t].se);
				t = p[t].fi;
			}
		}
		cout<<ans-tmp<<endl;
	}

}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}
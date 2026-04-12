#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()
 
#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

using namespace std;

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
} 

template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}


#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
 
#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue
 
#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}
#define jeb fflush(stdout)

int n;
vector<pair<PII,int> > v;
vector<pair<PII,int> > w;
vector<pair<int, PII> > e;
const int max_n = 3e5+5;
int fu[max_n];

int fup(int v) {
	return (fu[v] == v) ? v : (fu[v] = fup(fu[v]));
}

int main () {
	read(n);
	FOR(i,0,n) {
		make2(a, b);
		v.pb(mp(mp(a,b),i));
		w.pb(mp(mp(b,a),i));
	}
	sort(all(v));
	sort(all(w));
	FOR(i,0,n-1) {
		int c = min(abs(v[i].st.st-v[i+1].st.st), abs(v[i].st.nd-v[i+1].st.nd));
		int cw = min(abs(w[i].st.st-w[i+1].st.st), abs(w[i].st.nd-w[i+1].st.nd));
		PII x = mp(v[i].nd, v[i+1].nd);
		PII xw = mp(w[i].nd, w[i+1].nd);
		e.pb(mp(c,x));
		e.pb(mp(cw,xw));
	}
	sort(all(e));
	FOR(i,0,n) fu[i] = i;
	lint cost = 0;
	FORE(i, e) {
		int v = i->nd.st;
		int w = i->nd.nd;
		v = fup(v);
		w = fup(w);
		if (v == w) continue;
		cost += i->st;
		fu[v] = w;
	}
	printf("%lld\n", cost);

	return 0;
}

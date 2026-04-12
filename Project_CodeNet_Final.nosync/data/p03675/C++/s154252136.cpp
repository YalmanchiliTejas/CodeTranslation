#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(),(v).end()
 
#define PII pair<int,int>
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

int start = 2e5;
int meta = 2e5;

const int max_n = 5e5;

int a[max_n];

int main () {
	make(n);
	makev(v, n);
	a[start] = v[0];
	meta++;
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			a[start-1] = v[i];
			start--;
		} else {
			a[meta] = v[i];
			meta++;
		}
	}
	if (n%2 == 1) {
		for (int i = start; i != meta; i++) {
			printf("%d ", a[i]);
		}
	}
	else {
		for (int i = meta - 1; i >= start; i--) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}

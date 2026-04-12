#include<bits/stdc++.h>
#define REP(n)    for(int i = 0; i < (n); ++i)
#define RREP(n)   for(int i = (n); i >= 0; --i)
#define FOR(m, n) for(int i = (m); i < (n); ++i)
#define SZ(x)       ( (int)(x).size() )
#define BIT(n)      ( 1LL << (n) )
#define EXIST(x)    ( (x).find()		!= (x).end() )
#define DEBUG(n)    cerr << #n << " : " << n << '\n';
#define PB  push_back
#define UB  upper_bound			//k <
#define LB  lower_bound			//k	<= 
#define F   first
#define S   second
#define INF 1.0e9


using namespace std;

typedef long long			ll;
typedef pair<int, int>		pii;
typedef pair<long			long, long long>   pll;
typedef vector<int>			vi;
typedef vector<double>		vd;
typedef vector<long long>   vll
;

template<class T> void chmax(T &	a, const T & b){ if( a < b ) a = b; }
template<class T> void chmin(T &	a, const T & b){ if( a > b ) a = b; }

int r_up(const int a, const int b){ return (a + b - 1) / b; }

const int dx[] = { 0,  0, 1, -1 };
const int dy[] = { 1, -1, 0,  0 };

struct UFT{
  vi	p;
  UFT(){}
  UFT(int N)       { p.resize( N, -1 ); }
  int	par(int a)   { if( p[a] >= 0 ){ p[a]  = par( p[a] ); return p[a]; } return a;  }
  int size(int a)  { return -p[par(a)]; }
  bool	same(int a, int b) { return par(a)	 == par(b); }
  void unite(int	a, int b){
	a													  = par(a);  b = par(b);
	if( a == b ) return;
	if( size(a) < size(b) ) swap(a,b);
	p[a]												 -= size(b);
	p[b]												  = a;
  }
};

int main(){
  int n;cin>>n;
  switch(n){case 3:case 5:case 7:cout<<"YES\n";break;default: cout<<"NO\n";}
  return 0;
}

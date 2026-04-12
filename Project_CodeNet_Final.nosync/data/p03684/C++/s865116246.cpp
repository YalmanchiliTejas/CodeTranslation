#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;
const LL INF = 1e15;

class UnionFind{
private:
  vector<int> par, rank;
public:
  UnionFind(int n){
	par.assign(n, 0);
	rank.assign(n, 0);
	for(int i=0;i<n;++i)
	  par[i] = i;
  }

  //find root of x
  int find(int x){
	if(par[x] == x)
	  return x;
	return (par[x] = find(par[x]));
  }

  void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;

	if(rank[x] < rank[y])
	  par[x] = y;
	else{
	  par[y] = x;
	  if(rank[x] == rank[y])
		++rank[x];
	}
  }

  bool same(int x, int y){
	return find(x) == find(y);
  }
};

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<pair<PLL,int>> xs(N);
  REP(i,N){
	cin >> xs[i].FF;
	xs[i].SS = i;
  }
  vector<pair<LL,PII>> q;
  sort(ALL(xs), [](const pair<PLL,int>& l, const pair<PLL,int>& r){
	  return l.FF.FF < r.FF.FF;
	});
  REP(i,N-1){
	q.EB(xs[i+1].FF.FF - xs[i].FF.FF, PII(xs[i].SS, xs[i+1].SS));
  }
  sort(ALL(xs), [](const pair<PLL,int>& l, const pair<PLL,int>& r){
	  return l.FF.SS < r.FF.SS;
	});
  REP(i,N-1){
	q.EB(xs[i+1].FF.SS - xs[i].FF.SS, PII(xs[i].SS, xs[i+1].SS));
  }
  
  SORT(q);
  UnionFind uf(N);
  LL ans = 0;
  for(auto&& p: q){
	if(!uf.same(p.SS.FF, p.SS.SS)){
	  uf.unite(p.SS.FF, p.SS.SS);
	  ans += p.FF;
	}
  }
  cout << ans << endl;

  return 0;
}

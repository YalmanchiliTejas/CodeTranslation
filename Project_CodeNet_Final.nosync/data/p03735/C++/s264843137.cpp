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

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  int N2 = N * 2;
  vector<pair<PLL,int>> xs(N);
  vector<PLL> a(N2);
  REP(i,N){
	cin >> xs[i].FF;
	if(xs[i].FF.FF > xs[i].FF.SS)
	  swap(xs[i].FF.FF, xs[i].FF.SS);
	xs[i].SS = i;
	
	a[i*2] = MP(xs[i].FF.FF, i);
	a[i*2+1] = MP(xs[i].FF.SS, i);
  }
  SORT(a);
  SORT(xs);
  LL ans = 1e18;

  {
	LL mn = a.front().FF;
	LL mx = a.back().FF;
	REP(i,N){
	  if(a.front().SS != xs[i].SS)
		maxi(mn, xs[i].FF.FF);
	  if(a.back().SS != xs[i].SS)
		mini(mx, xs[i].FF.SS);
	}

	LL d1 = mn - a.front().FF;
	LL d2 = a.back().FF - mx;
	mini(ans, d1*d2);
  }
  if(a.front().SS != a.back().SS){
	LL d = a.back().FF - a.front().FF;
	multiset<LL> mt;
	REP(i,N){
	  if(a.front().SS == xs[i].SS){
		mt.insert(xs[i].FF.SS);
	  }
	  else{
		mt.insert(xs[i].FF.FF);
	  }
	}
	mini(ans, (*mt.rbegin() - *begin(mt)) * d);
	REP(i,N){
	  if(a.front().SS != xs[i].SS && a.back().SS != xs[i].SS){
		mt.erase(mt.find(xs[i].FF.FF));
		mt.insert(xs[i].FF.SS);
		mini(ans, (*mt.rbegin() - *begin(mt)) * d);
	  }
	}
  }
  
  cout << ans << endl;

  return 0;
}

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

  LL N;
  cin >> N;
  VL xs(N);
  REP(i,N) cin >> xs[i];

  LL ans = 0;
  while(true){
	RSORT(xs);
	
	if(xs[0] < 1000) break;
	int e = 1;
	for(;e<N;++e)
	  if(xs[e-1] - xs[e] >= N+1) break;
	if(e == N) break;

	LL k = (xs[e-1] - xs[e]) / (N+1);
	REP(i,e){
	  xs[i] += (-N + e-1) * k;
	}
	FOR(i,e,N){
	  xs[i] += e*k;
	}
	ans += e*k;
  }
  if(xs[0] > 1000){
	LL d = xs[0] - 1000;
	ans += d*N;
	REP(i,N) xs[i] -= d;
  }

  while(true){
	RSORT(xs);
	if(xs[0] < N) break;
	xs[0] -= N;
	FOR(i,1,N) ++xs[i];
	++ans;
  }
  cout << ans << endl;

  return 0;
}

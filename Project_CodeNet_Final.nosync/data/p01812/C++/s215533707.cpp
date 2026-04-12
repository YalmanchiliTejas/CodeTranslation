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

int N, M, K;
int ds[16];
int isd[101];
int memo[1<<16];
int solve(const VVI& G, int b){
  if(b == 0) return 0;
  if(memo[b] >= 0) return memo[b];

  int& res = memo[b];
  res = 1e6;
  REP(k,K){
	int nb = 0;
	REP(i,M){
	  if((b>>i&1)){
		int to = G[ds[i]][k];
		if(isd[to] >= 0)
		  nb |= 1 << isd[to];
	  }
	}
	mini(res, solve(G, nb) + 1);
  }

  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  fill(memo, memo+(1<<16), -1);
  fill(isd, isd+101, -1);

  cin >> N >> M >> K;
  REP(i,M){
	cin >> ds[i];
	isd[ds[i]] = i;
  }

  VVI G(N+1, VI(K));
  REP(i,N) REP(k,K) cin >> G[i+1][k];

  cout << solve(G, (1<<M)-1) << endl;  

  return 0;
}
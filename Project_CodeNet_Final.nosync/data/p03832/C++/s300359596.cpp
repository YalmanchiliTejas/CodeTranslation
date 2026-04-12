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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, pair<S,T>& p){
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
struct PH{
  template<class T, class U>
  size_t operator()(const pair<T,U>& x) const{
	return hash<T>()(x.first) ^ hash<U>()(x.second);
  }
};

LL dp[1010][1010];
LL fact[1010];

LL powm(LL x, LL y){
  if(y == 0) return 1;
  return powm(x*x%MOD, y/2) * (y%2==1?x:1) % MOD;
}

unordered_map<LL,LL> memo;
LL inv(LL x){
  if(memo.count(x)) return memo[x];
  return memo[x] = powm(x, MOD-2);
}

LL CH(LL n, LL m){
  return fact[n] * inv(fact[n-m] * fact[m] % MOD) % MOD;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  fact[0] = 1;
  REP(i,1001)
	fact[i+1] = fact[i] * (i+1) % MOD;
  
  LL N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;

  dp[A][N] = 1;
  for(int i=A;i<=B;++i){
	REP(n,N+1)
	  dp[i+1][n] = dp[i][n];

	LL tmp = 1;
	for(int j=1;j<=D&&i*j<=N;++j){
	  (tmp *= CH(i*j-1, i-1)) %= MOD;
	  if(j < C) continue;
	  
	  for(int n=i*j;n<=N;++n)
		(dp[i+1][n-i*j] += dp[i][n] * CH(n,i*j) % MOD
		 * tmp % MOD) %= MOD;
	}
  }

  cout << dp[B+1][0] << endl;

  return 0;
}

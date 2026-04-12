#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-6;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

// const int64 mod = 1e9+7;
int64 N, mod;

int64 fact[3030], inv[3030];
int64 dp[3030][3030] = {};

int64 mpow(int64 a, int64 b, int64 m){
	if(b == 0) return 1;
	if(b%2) return a*mpow(a, b-1, m)%m;
	int64 ret = mpow(a, b/2, m);
	return ret*ret%m;
}

int64 comb(int64 a, int64 b){
	return fact[a]*inv[b]%mod*inv[a-b]%mod;
}

void init(){
	fact[0] = 1;
	REP(i, 3029) fact[i+1] = (fact[i]*(i+1))%mod;
	REP(i, 3030) inv[i] = mpow(fact[i], mod-2, mod);
	REP(i, 3030) dp[i][0] = 1;
	FOR(i, 1, 3030){
		FOR(j, 1, 3030){
			dp[i][j] = dp[i-1][j]*(j+1)+dp[i-1][j-1];
			dp[i][j] %= mod;
		}
	}
}

int64 f(int64 x){
	int64 ret = 0;
	int64 p = mpow(2, (N-x), mod);
	int64 pa = 1;
	int64 pb = mpow(2, mpow(2, N-x, mod-1), mod);
	FOR(i, 0, x+1){
		ret += dp[x][i]*pa%mod*pb%mod;
		ret %= mod;
		pa = pa*p%mod;
	}
	return ret;
}

int main(void){
	cin >> N >> mod;
	init();

	int64 res = 0;
	REP(i, N+1){
		if(i%2) res = (res-comb(N, i)*f(i)%mod+mod)%mod;
		else res = (res+f(i)*comb(N, i)%mod)%mod;
	}
	cout << res << endl;
}
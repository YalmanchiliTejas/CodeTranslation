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

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

const int64 mod = 1e9+7;

int64 fact[1010], inv[1010];

int64 mpow(int64 a, int64 b){
	if(b == 0) return 1;
	if(b%2) return a*mpow(a, b-1)%mod;
	int64 ret = mpow(a, b/2);
	return ret*ret%mod;
}

void init(){
	fact[0] = 1; inv[0] = 1;
	REP(i, 1009) fact[i+1] = fact[i]*(i+1)%mod;
	REP(i, 1010) inv[i] = mpow(fact[i], mod-2);
}

int64 comb(int64 a, int64 b){
	if(a < b) return 0;
	return fact[a]*inv[b]%mod*inv[a-b]%mod;
}

int main(void){
	int64 N, K;
	cin >> N >> K;
	int64 res = 0;
	if(K == 0){
		cout << N*N << endl;
		return 0;
	}
	FOR(i, K+1, N+1){
		res += (i-K)*((N+1)/i);
		if((N+1)%i >= K)
			res += ((N+1)%i-K);
	}
	cout << res << endl;
}
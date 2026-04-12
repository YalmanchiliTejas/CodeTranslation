#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
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

using Row = vector<int64>;
using Mat = vector<Row>;

string N;
int32 D;
int64 dp[10010][2][101];

int64 rec(int32 k = 0, bool tight = 1, int32 mo = 0){  
	if(k == N.size()){
		return mo == 0;
	}
	int32 x = N[k] - '0';
	int32 r = (tight ? x : 9);
	int64 &res = dp[k][tight][mo];
	if(~res) return res;
	res = 0;
	for(int32 i = 0;i <= r;i++){
		 res += rec(k + 1, tight && i == r, (mo + i)%D);
		 res %= mod;
	}
	return res;
}

int main(void){
	cin >> N >> D;
	memset(dp, -1, sizeof dp);
	cout << (rec()-1+mod)%mod << endl;

}

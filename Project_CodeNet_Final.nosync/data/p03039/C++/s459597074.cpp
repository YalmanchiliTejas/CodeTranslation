#include "bits/stdc++.h"

#define REP(i, n, N) for(ll i=(n); i<(N); i++)
#define RREP(i, n, N) for(ll i=(N-1); i>=n; i--)
#define CK(n, a, b) ((a)<=(n)&&(n)<(b))
#define ALL(v) (v).begin(),(v).end()
#define MCP(a, b) memcpy(b,a,sizeof(b))
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
#define v2(T) vector<vector<T>>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll N, M, K;
ll ans;

class FermatCombination {
private:

	long long MOD;

public:
	long long factrial[201010]; //階乗を保持
	long long inverse[201010];  //逆元を保持
	FermatCombination(ll size, long long mod);
	long long combine(ll n, ll k);
	long long fast_pow(long long x, ll n);
};

FermatCombination::FermatCombination(ll size, long long mod) {

	MOD = mod;

	factrial[0] = 1;
	inverse[0] = 1;

	for (ll i = 1; i <= size; i++) {
		factrial[i] = (factrial[i - 1] * i) % MOD;  // 階乗を求める
		inverse[i] = fast_pow(factrial[i], (int)MOD - 2) % MOD; // フェルマーの小定理で逆元を求める
	}
}

long long FermatCombination::combine(ll n, ll k) {
	return factrial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}

long long FermatCombination::fast_pow(long long x, ll n) { // x^n 計算量O(logn)
	long long ans = 1;
	while (n > 0) {
		if ((n & 1) == 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD; // 一周する度にx, x^2, x^4, x^8となる
		n >>= 1;         // 桁をずらす n = n >> 1
	}
	return ans;
}

int main() {
	cin>>N>>M>>K;
	FermatCombination fc(N*M, mod);
	ll nmCk = fc.combine(N*M-2, K-2);
	ll sum = M*M %mod;
	sum *= nmCk % mod;
	sum %= mod;
	ll tmp=0;
	REP(i,1,N){
		tmp+=i;
		tmp%=mod;
		ans += (sum*tmp) %mod;
		ans %= mod;
	}
	sum = N*N % mod;
	sum *= nmCk % mod;
	sum %= mod;
	tmp = 0;
	REP(i,1,M){
		tmp+=i;
		tmp%=mod;
		ans += (sum*tmp) %mod;
		ans %= mod;
	}
	p(ans % mod);
	return 0;
}

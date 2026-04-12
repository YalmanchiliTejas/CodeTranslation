#include "bits/stdc++.h"
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define RREP(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define RFOR(i, s, n) for (int i = (int)n - 1; i >= s; --i)
#define ALL(a) a.begin(), a.end()
#define IN(a, x, b) (a <= x && x < b)
template<class T>inline void out(T t){cout << t << "\n";}
template<class T,class... Ts>inline void out(T t,Ts... ts){cout << t << " ";out(ts...);}
template<class T>inline bool CHMIN(T&a,T b){if(a > b){a = b;return true;}return false;}
template<class T>inline bool CHMAX(T&a,T b){if(a < b){a = b;return true;}return false;}
constexpr int INF = 1e18;

template<int MOD> struct Fp {
	long long val;
	constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
		if (val < 0) val += MOD;
	}
	constexpr int getmod() { return MOD; }
	constexpr Fp operator - () const noexcept {
		return val ? MOD - val : 0;
	}
	constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
	constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
	constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
	constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
	constexpr Fp& operator += (const Fp& r) noexcept {
		val += r.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}
	constexpr Fp& operator -= (const Fp& r) noexcept {
		val -= r.val;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr Fp& operator *= (const Fp& r) noexcept {
		val = val * r.val % MOD;
		return *this;
	}
	constexpr Fp& operator /= (const Fp& r) noexcept {
		long long a = r.val, b = MOD, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr bool operator == (const Fp& r) const noexcept {
		return this->val == r.val;
	}
	constexpr bool operator != (const Fp& r) const noexcept {
		return this->val != r.val;
	}
	friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
		return os << x.val;
	}
	friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
		if (n == 0) return 1;
		auto t = modpow(a, n / 2);
		t = t * t;
		if (n & 1) t = t * a;
		return t;
	}
};
 
// 二項係数ライブラリ
template<class T> struct BiCoef {
	vector<T> fact_, inv_, finv_;
	constexpr BiCoef() {}
	constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
		init(n);
	}
	constexpr void init(int n) noexcept {
		fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
		int MOD = fact_[0].getmod();
		for(int i = 2; i < n; i++){
			fact_[i] = fact_[i-1] * i;
			inv_[i] = -inv_[MOD%i] * (MOD/i);
			finv_[i] = finv_[i-1] * inv_[i];
		}
	}
	constexpr T com(int n, int k) const noexcept {
		if (n < k || n < 0 || k < 0) return 0;
		return fact_[n] * finv_[k] * finv_[n-k];
	}
	constexpr T fact(int n) const noexcept {
		if (n < 0) return 0;
		return fact_[n];
	}
	constexpr T inv(int n) const noexcept {
		if (n < 0) return 0;
		return inv_[n];
	}
	constexpr T finv(int n) const noexcept {
		if (n < 0) return 0;
		return finv_[n];
	}
};
 
const int MOD = 1000000007;
// const int MOD = 
using mint = Fp<MOD>;
BiCoef<mint> bc;
// bc.init(500050);

int dp[200010][4];

signed main(){
	int N;
	cin >> N;
	if(N == 1){
		out(0);
		return 0;
	}
	vector<int>a(N);
	REP(i,N){
		cin >> a[i];
	}
	REP(i,200010)REP(j,3)dp[i][j] = -INF;
	dp[0][0] = 0;
	REP(i,N){
		REP(j,2){
			CHMAX(dp[i + 1][j + 1],dp[i][j]);
		}
		//if(i + 2 <= N + 1)CHMAX(dp[min(N,i + 2)][2],dp[i][0]);
		REP(j,3)CHMAX(dp[min(N,i + 2)][j],dp[i][j] + a[i]);
	}
	if(N % 2)out(max(dp[N][1],dp[N][2]));
	else out(max(dp[N][0],dp[N][1]));
}
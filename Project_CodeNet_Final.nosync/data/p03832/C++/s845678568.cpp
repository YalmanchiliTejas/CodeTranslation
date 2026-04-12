#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
//#include "libs.h"
#include <random>
#include <unordered_map>
#include <unordered_set>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>

using namespace std;

//呪文
#define DUMPOUT cerr
#define dump(...) DUMPOUT<<"  ";DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;DUMPOUT<<"    ";dump_func(__VA_ARGS__)

typedef unsigned uint; typedef long long ll; typedef unsigned long long ull; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<double, double> pdd; typedef pair<string, string> pss;
template <typename _KTy, typename _Ty> ostream& operator << (ostream& o, const pair<_KTy, _Ty>& m) { o << "{" << m.first << ", " << m.second << "}"; return o; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& o, const map<_KTy, _Ty>& m) { if (m.empty()) { o << "{ }"; return o; } o << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { o << ", " << *itr; } o << "}"; return o; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& o, const unordered_map<_KTy, _Ty>& m) { if (m.empty()) { o << "{ }"; return o; } o << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { o << ", " << *itr; } o << "}"; return o; }
template <typename _Ty> ostream& operator << (ostream& o, const vector<_Ty>& v) { if (v.empty()) { o << "{ }"; return o; } o << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { o << ", " << *itr; } o << "}"; return o; }
template <typename _Ty> ostream& operator << (ostream& o, const set<_Ty>& s) { if (s.empty()) { o << "{ }"; return o; } o << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { o << ", " << *itr; } o << "}"; return o; }
template <typename _Ty> ostream& operator << (ostream& o, const unordered_set<_Ty>& s) { if (s.empty()) { o << "{ }"; return o; } o << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { o << ", " << *itr; }	o << "}"; return o; }
template <typename _Ty> ostream& operator << (ostream& o, const stack<_Ty>& s) { if (s.empty()) { o << "{ }"; return o; } stack<_Ty> t(s); o << "{" << t.top(); t.pop(); while (!t.empty()) { o << ", " << t.top(); t.pop(); } o << "}";	return o; }
template <typename _Ty> ostream& operator << (ostream& o, const list<_Ty>& l) { if (l.empty()) { o << "{ }"; return o; } o << "{" << l.front(); for (auto itr = ++l.begin(); itr != l.end(); ++itr) { o << ", " << *itr; } o << "}"; return o; }
template <typename _KTy, typename _Ty> istream& operator >> (istream& is, pair<_KTy, _Ty>& m) { is >> m.first >> m.second; return is; }
template <typename _Ty> istream& operator >> (istream& is, vector<_Ty>& v) { for (size_t i = 0; i < v.size(); i++) is >> v[i]; return is; }
namespace aux { // print tuple
	template<typename Ty, unsigned N, unsigned L> struct tp { static void print(ostream& os, const Ty& v) { os << get<N>(v) << ", "; tp<Ty, N + 1, L>::print(os, v); } };
	template<typename Ty, unsigned N> struct tp<Ty, N, N> { static void print(ostream& os, const Ty& v) { os << get<N>(v); } };
}
template<typename... Tys> ostream& operator<<(ostream& os, const tuple<Tys...>& t) { os << "{"; aux::tp<tuple<Tys...>, 0, sizeof...(Tys) - 1>::print(os, t); os << "}"; return os; }

template<typename A, size_t N, typename T> inline void Fill(A(&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head&& head, Tail&&... tail) { DUMPOUT << head; if (sizeof...(Tail) == 0) { DUMPOUT << " "; } else { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#define PI 3.14159265358979323846
#define EPS 1e-10
#define FOR(i,a,n) for(int i=(a);i<(n);++i)
#define REP(i,n)  FOR(i,0,n)
#define all(j) (j).begin(), (j).end()
#define SZ(j) ((int)(j).size())
#define fake false



constexpr ll MOD = 1000000007;
ll modfac[1010];
ll modfacinv[1010];

// 拡張ユークリッド互除法 (入力 : 整数 a, n, 出力 : GCD(a, n) と xa + yb = GCD(a, n) を満たす整数 x, y)
template<typename Ty> void ExEuclid(Ty a, Ty b, Ty& gcd, Ty& x, Ty& y) {
	Ty r1, r2, r3, x1, x2, x3, y1, y2, y3, q;
	r1 = a; x1 = 1; y1 = 0;
	r2 = b; x2 = 0; y2 = 1;
	while (r2 != 0) {
		r3 = r1 % r2;
		q = r1 / r2;
		x3 = x1 - q * x2;
		y3 = y1 - q * y2;
		r1 = r2; r2 = r3;
		x1 = x2; x2 = x3;
		y1 = y2; y2 = y3;
	}
	gcd = r1; x = x1; y = y1;
	if (gcd < 0) { gcd *= -1; x *= -1; y *= -1; };
}

// a と m は互いに素が前提
template<typename Ty> Ty invmod(Ty a, Ty m) {
	Ty gcd, x, q;
	ExEuclid(a, -m, gcd, x, q);
	if (gcd != 1) return -1;
	return x;
}

// n^e mod m
template<typename Ty> Ty modpow(Ty n, Ty e, Ty m) {
	Ty result = 1;
	while (e > 0) {
		if (e & 1) result = (result * n) % m;
		e >>= 1;
		n = (n * n) % m;
	}
	return result;
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	modfac[0] = 1;
	for (ll i = 1; i <= 1000; i++)
		modfac[i] = modfac[i - 1] * i % MOD;
	for (ll i = 0; i <= 1000; i++)
		modfacinv[i] = invmod(modfac[i], MOD);

	ll N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;

	vector<vector<ll>> dp(B + 1, vector<ll>(N + 1, 0));
	REP(i, A) dp[i][0] = 1;

	for (ll i = A; i <= B; i++) {
		for (ll j = 0; j <= N; j++) {
			dp[i][j] += dp[i - 1][j];
			for (ll k = C; k <= D; k++) {
				ll n = j - k * i;
				if (n < 0) break;
				ll c = dp[i - 1][n] * modfac[N - n] % MOD * modfacinv[N - j] % MOD * modfacinv[k] % MOD * invmod(modpow(modfac[i], k, MOD), MOD) % MOD;
				dp[i][j] = (dp[i][j] + c) % MOD;
			}
		}
	}

	cout << (dp[B][N] + MOD) % MOD << endl;

	return 0;
}

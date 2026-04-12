#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#include <random>
#include <unordered_map>
#include <unordered_set>

#define LOCAL

using namespace std;

//呪文
#define DUMPOUT cerr
#define dump(...) DUMPOUT<<"  ";DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;DUMPOUT<<"    ";dump_func(__VA_ARGS__)

typedef unsigned uint; typedef long long ll; typedef unsigned long long ull; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<double, double> pdd; typedef pair<string, string> pss;
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { ostr << "{" << m.first << ", " << m.second << "}"; return ostr; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const unordered_map<_KTy, _Ty>& m) { if (m.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const unordered_set<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const stack<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; } stack<_Ty> t(s); ostr << "{" << t.top(); t.pop(); while (!t.empty()) { ostr << ", " << t.top(); t.pop(); } ostr << "}";	return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const list<_Ty>& l) { if (l.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << l.front(); for (auto itr = ++l.begin(); itr != l.end(); ++itr) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
template <typename _KTy, typename _Ty> istream& operator >> (istream& istr, pair<_KTy, _Ty>& m) { istr >> m.first >> m.second; return istr; }
template <typename _Ty> istream& operator >> (istream& istr, vector<_Ty>& v) { for (size_t i = 0; i < v.size(); i++) istr >> v[i]; return istr; }
namespace aux { // print tuple
	template<typename Ty, unsigned N, unsigned L> struct tp { static void print(ostream& os, const Ty& v) { os << get<N>(v) << ", "; tp<Ty, N + 1, L>::print(os, v); } };
	template<typename Ty, unsigned N> struct tp<Ty, N, N> { static void print(ostream& os, const Ty& value) { os << get<N>(value); } };
}
template<typename... Tys> ostream& operator<<(ostream& os, const tuple<Tys...>& t) { os << "{"; aux::tp<tuple<Tys...>, 0, sizeof...(Tys)-1>::print(os, t); os << "}"; return os; }

template<typename A, size_t N, typename T> inline void Fill(A(&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head&& head, Tail&&... tail) { DUMPOUT << head; if (sizeof...(Tail) == 0) { DUMPOUT << " "; } else { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#define PI 3.14159265358979323846
#define EPS 1e-8
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fake false



struct SXor128 {
	unsigned x, y, z, w;
	SXor128() { x = 123456789; y = 362436069; z = 521288629; w = 88675123; }
	SXor128(int _w) { x = 123456789; y = 362436069; z = 521288629; w = _w; }
	void setSeed() { x = 123456789; y = 362436069; z = 521288629; w = 88675123; }
	void setSeed(int _w) { x = 123456789; y = 362436069; z = 521288629; w = _w; }
	unsigned nextUInt() {
		unsigned t = (x ^ (x << 11));
		x = y; y = z; z = w;
		return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
	}
	unsigned nextUInt(unsigned mod) {
		unsigned t = (x ^ (x << 11));
		x = y; y = z; z = w;
		w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
		return w % mod;
	}
	unsigned nextUInt(unsigned l, unsigned r) {
		unsigned t = (x ^ (x << 11));
		x = y; y = z; z = w;
		w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
		return w % (r - l + 1) + l;
	}
	double nextDouble() {
		return double(nextUInt()) / UINT_MAX;
	}
};



int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, K;
	cin >> N >> K;

	ll ans = 0;
	for (ll b = 1; b <= N; b++) {
		ll s = (N + 1) / b;
		ll t = (N + 1) % b;
		ans += (N + 1) - min(K, b) * s - min(K, t);
	}
	cout << ans - (K == 0 ? N : 0) << endl;

	return 0;
}
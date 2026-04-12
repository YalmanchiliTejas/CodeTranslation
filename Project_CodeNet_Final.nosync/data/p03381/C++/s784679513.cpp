#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#include <random>

using namespace std;

//呪文
#define DUMPOUT cerr
#define dump(...) DUMPOUT<<"  ";DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;DUMPOUT<<"    ";dump_func(__VA_ARGS__)

typedef unsigned uint; typedef long long ll; typedef unsigned long long ull; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<double, double> pdd; typedef pair<string, string> pss;
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { ostr << "{" << m.first << ", " << m.second << "}"; return ostr; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
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
#define EPS 1e-11
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fake false



int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	// val, index
	vector<pll> v(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(all(v));

	// 左半分なら false
	vector<bool> lr(N + 1, false);
	for (int i = N / 2 + 1; i <= N; i++) lr[v[i].second] = true;

	ll val_right = v[N / 2 + 1].first; // 左半分を取り除いた場合の中央値
	ll val_left = v[N / 2].first; // 右半分

	vector<ll> ans(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		if (lr[v[i].second]) ans[v[i].second] = val_left;
		else ans[v[i].second] = val_right;
	}

	for (int i = 1; i <= N; i++) cout << ans[i] << endl;

	return 0;
}

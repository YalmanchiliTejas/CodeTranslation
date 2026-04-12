#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#include <random>
//#include "util.r"

using namespace std;

//呪文
#define DUMPOUT cout
#define dump(...) DUMPOUT<<"  ";DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;DUMPOUT<<"    ";dump_func(__VA_ARGS__)

typedef unsigned uint; typedef long long ll; typedef unsigned long long ull; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<double, double> pdd; typedef pair<string, string> pss;
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { ostr << "{" << m.first << ", " << m.second << "}"; return ostr; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const stack<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; } stack<_Ty> t(s); ostr << "{" << t.top(); t.pop(); while (!t.empty()) { ostr << ", " << t.top(); t.pop(); } ostr << "}";	return ostr; }
template <typename _KTy, typename _Ty> istream& operator >> (istream& istr, pair<_KTy, _Ty>& m) { istr >> m.first >> m.second; return istr; }
template <typename _Ty> istream& operator >> (istream& istr, vector<_Ty>& v) { for (size_t i = 0; i < v.size(); i++) istr >> v[i]; return istr; }
ll modpow(ll n, ll p, ll m) { ll result = 1; while (p > 0) { if (p & 1) result = (result * n) % m; p >>= 1; n = (n * n) % m; } return result; }
template <typename _Ty> _Ty ipow(_Ty x, _Ty n) { _Ty ret = _Ty(1); for (_Ty i = _Ty(0); i < n; i++) ret *= x; return ret; }
template<typename A, size_t N, typename T> inline void Fill(A(&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head&& head, Tail&&... tail) { DUMPOUT << head; if (sizeof...(Tail) == 0) { DUMPOUT << " "; } else { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#define PI 3.14159265358979323846
#define EPS 1e-11
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define all(x) (x).begin(), (x).end()
#define fake false



int N, M;
int ans = 0;
vector<vector<int>> G;

void rec(int v = 0, int bit = 1) {
	if (bit == (1 << N) - 1) {
		ans++; return;
	}

	for (int& w : G[v]) {
		if (bit & (1 << w)) continue;
		rec(w, bit ^ (1 << w));
	}
}

int main()
{
	//clock_t start, end;
	//start = clock();

	
	cin >> N >> M;
	G.resize(N);	

	REP(i, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b); G[b].push_back(a);
	}

	rec();

	cout << ans << endl;

	//end = clock();
	//printf("%d msec.\n", end - start);

	return 0;
}

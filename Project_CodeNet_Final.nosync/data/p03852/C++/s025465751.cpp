#pragma warning(disable:4996)
#include <bits/stdc++.h>

using namespace std;

//macro
#define FOR(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define EPS (1e-8)
#define equals(a,b)(fabs((a)-(b))<EPS)

using ll = long long;
using ull = unsigned long long;
using vb = vector<bool>;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vvb = vector<vb>;
using vvi = vector<vi>;
using vvll = vector<vll>;
//func
template<typename A, typename T>void assign2d(A&arr, ll H, ll W, T t) { arr.resize(H); REP(i, H) arr[i].assign(W, t); }
template<class T> ostream &operator<<(ostream &os, const vector<T> &v) { int n = v.size(); REP(i, n)os << v[i] << (i == n - 1 ? "" : " "); return os; }
template <class T = int> inline T IN() { T x; cin >> x; return x; }
template<class T> inline void OUT(const T &x) { cout << x << "\n"; }
void YESNO(bool c) { OUT(c ? "YES" : "NO"); };
void YesNo(bool c) { OUT(c ? "Yes" : "No"); };
struct pre_ { pre_() { cin.tie(nullptr); ios::sync_with_stdio(false); /*cout << fixed << setprecision(6);*/ } } pre__;

bool check(char c) {
	char A[5] = { 'a', 'i', 'u', 'e', 'o' };
	REP(i, 5) {
		if (c == A[i])return true;
	}
	return false;
}

int main() {
	char c;
	cin >> c;
	cout << (check(c) ? "vowel" : "consonant") << endl;
	return 0;
}
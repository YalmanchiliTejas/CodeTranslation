#include<bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
 
template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}
 
void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}
 
#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
template<class T> int size(T && a) { return a.size(); }

using LL = long long;
using PII = pair<int, int>;

int mod = 998244353;
int mul(int a, int b) { return (LL) a * b % mod; }
int add(int a, int b) { return a + b < mod ? a + b : a + b - mod; }
int qpow(int a, int n) {
	if(n == 0) return 1;
	if(n % 2 == 1) return mul(qpow(a, n - 1), a);
	return qpow(mul(a, a), n / 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> rev(n + 1, 1);
	int fac = 1;
	FOR(i, 1, n) fac = mul(fac, i);
	rev[n] = qpow(fac, mod - 2);
	for(int i = n; i >= 2; i--)
		rev[i - 1] = mul(rev[i], i);
	auto choose_k = [&](int k) {
		int res = fac;
		res = mul(res, rev[k]);
		res = mul(res, rev[n - k]);
		return res;
	};

	int ans = qpow(3, n);
	int bad = 0, p = 1;
	for(int i = n; i * 2 > n; i--) {
		int res = mul(choose_k(i), p);
		bad = add(bad, res);
		p = mul(p, 2);
	}

	bad = mul(2, bad);
	bad = add(mod, -bad);
	ans = add(ans, bad);

	cout << ans << "\n";
}

#include<bits/stdc++.h>
using namespace std;
string to_string(const string& s) {
	return '"' + s + '"';
}
string to_string(const bool b) {
	return (b ? "true" : "false");
}
string to_string(const char* s) {
	return to_string((string)s);
}
string to_string(const char c) {
	string s = "'";
	s += c;
	s += "'";
	return s;
}
template<class T, class U>
string to_string(const pair<T, U>& p) {
	string s = "(";
	s += to_string(p.first);
	s += ", ";
	s += to_string(p.second);
	s += ")";
	return s;
}
template<class T>
string to_string(const T& a) {
	bool first = true;
	string s = "{";
	for (const auto& x : a) {
		if(!first){
			s += ", ";
		}
		first = false;
		s += to_string(x);
	}
	s += "}";
	return s;
}
void debug_out() {cerr << '\n';}
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int inf = 1e9 + 100;
const ll inf64 = 7e18l;
int add(int x, int y) {
	x += y;
	if (x  >= mod) {
		x -= mod;
	}
	return x;
}
void add_self(int& x, int y) {
	x = add(x, y);
}
int mult(int x, int y) {
	return 1ll * x * y % mod;
}
void mult_self(int& x, int y) {
	x = mult(x, y);
}
int bin_pow(int x, int y) {
	if (y == 0) {
		return 1;
	}
	if (y % 2 == 0) {
		return bin_pow(mult(x, x), y / 2);
	}
	return mult(x, bin_pow(x, y - 1));
}
int inv(int x) {
	return bin_pow(x, mod - 2);
}
const int maxn = 2e5 + 10;
vector<int> fact(maxn), inv_fact(maxn);
int C(int x, int y) {
	if (x < y) {
		return 0;
	}
	return mult(mult(fact[x], inv_fact[y]), inv_fact[x - y]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	for (int i = 0; i < maxn; ++i) {
		if (i == 0) {
			fact[i] = 1;
		} else {
			fact[i] = mult(fact[i - 1], i);
		}
		inv_fact[i] = inv(fact[i]);
	}
	int n, m, k;
	cin >> n >> m >> k;
	int answer = 0;
	for (int len = 1; len < n; ++len) {
		add_self(answer, mult(mult(n - len, mult(m, m)), len));
	}
	for (int len = 1; len < m; ++len) {
		add_self(answer, mult(mult(m - len, mult(n, n)), len));
	}
	mult_self(answer, C(n * m - 2, k - 2));
	cout << answer << '\n';
}

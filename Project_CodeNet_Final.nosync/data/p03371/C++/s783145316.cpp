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
const int mod = 998244353;
const int inf = 1e9 + 100;
const ll inf64 = 7e18l;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	int a, b, c;
	cin >> a >> b >> c;
	int x, y;
	cin >> x >> y;
	int mn = min(x, y);
	int answer = 0;
	if (a + b >= 2 * c) {
		answer += mn * 2 * c;
	} else {
		answer += mn * (a + b);
	}
	debug(answer);
	x -= mn;
	y -= mn;
	if (y == 0) {
		if (2 * c <= a) {
			answer += x * 2 * c;
		} else {
			answer += x * a;
		}
	} else {
		if (2 * c <= b) {
			answer += y * 2 * c;
		} else {
			answer += y * b;
		}
	}
	cout << answer << '\n';
 	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string(string(s)); }
string to_string(bool b) { return to_string(int(b)); }
string to_string(char b) { return "'" + string(1, b) + "'"; }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v) {
	string res = "{";
	for (const auto& x : v) res += (res == "{" ? "" : ", ") + to_string(x);
	return res + "}";
}
void debug() { cerr << endl; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug(T...);
}
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define db(...) 42
#endif
typedef long long ll;
typedef long double ld;
int main() {
	int n;
	scanf("%d", &n);
	deque<int> b;
	bool rev = false;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (!rev) b.push_back(a);
		else b.push_front(a);
		rev = !rev;
	}
	vector<int> ans(b.begin(), b.end());
	if (rev) reverse(ans.begin(), ans.end());
	for (int a : ans) printf("%d ", a);
}

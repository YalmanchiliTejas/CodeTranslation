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
	ll n;
	scanf("%lld", &n);
	int x, m;
	scanf("%d%d", &x, &m);
	vector<int> used(m);
	vector<ll> sum(m);
	int a = x;
	ll s = 0;
	bool proc = false;
	for (ll i = 1; i <= n;) {
		if (used[a] && !proc) {
			ll cycleSum = s - sum[a];
			int cycleLen = i - used[a];
			ll rounds = (n - i - 1) / cycleLen;
			s += rounds * cycleSum;
			i += rounds * cycleLen;
			proc = true;
			continue;
		}
		used[a] = i;
		sum[a] = s;
		s += a;
		a = (ll)a * a % m;
		++i;
	}
	printf("%lld\n", s);
}

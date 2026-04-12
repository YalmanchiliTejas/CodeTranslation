#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
using uint = unsigned int;
using ull = unsigned long long;

template<typename T> using uset = unordered_set<T>;
template<typename T1, typename T2> using umap = unordered_map<T1, T2>;

constexpr int INF = (1 << 30) - 1;
constexpr ll LLINF = 1LL << 60;
constexpr int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr char el = '\n';
constexpr int mod = 1000000007;

template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

template<typename T>
ostream& operator <<(ostream &os, vector<T> &v) {
	for (auto &u : v) os << u << el;
	return (os);
}

template<typename T>
istream& operator >>(istream &is, vector<T> &v) {
	for (auto &u : v) is >> u;
	return (is);
}

template<typename T1, typename T2>
istream& operator >>(istream &is, pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return (is);
}


ll power(ll n, ll k) {
	ll d = 1;
	for (ll i = 0; i < k; i++) d *= n;
	return (d);
}

ll choose(ll n, ll k) {
	ll f = 1;
	ll ans = 1;
	if (n < k) return (0);

	for (ll i = 1; i <= k; i++) {
		ans *= (n - i + 1);
		f *= i;
	}
	return (ans / f);
}
ll calc(string S, int K) {
	ll ret = 0;
	
	if (S.size() == 0 || K <= 0) return (0);
	if (S[0] == '0') return (calc(S.substr(1, S.size() - 1), K));

	ll val = S[0] - '0';
	
	for (int i = 0; i < val; i++) {
		ll k = K;
		if (i > 0) k--;
		ret += power(9, k) * choose(S.size() - 1, k);
	}

	string T = S.substr(1, S.size() - 1);
	if (K - 1 == 0 && val > 0) ret += 1;

	else ret += calc(T, K - 1);
	return (ret);
}

int main() {
	string S;	
	int K;
	cin >> S >> K;
	cout << calc(S, K) << endl;
	return (0);
}

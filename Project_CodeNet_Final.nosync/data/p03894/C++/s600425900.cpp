#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
using vvint = vector<vint>;
using vvvint = vector<vvint>;
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
	return (is >> p.first >> p.second);
}

int main() {
	ll N, Q; cin >> N >> Q;
	vll dat(N);
	iota(begin(dat), end(dat), 1);

	set<int> st;
	st.insert(1); st.insert(2);
	int pos = 0;
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b; --a, --b;
		swap(dat[a], dat[b]);
		if (a == pos) pos = b;
		else if (b == pos) pos = a;
		if (pos > 0) st.insert(dat[pos-1]);
		if (pos < N-1) st.insert(dat[pos+1]);
	}
	cout << st.size() << endl;
	return (0);
}
#include "bits/stdc++.h"
using namespace std;

using int64 = long long;

using vint = vector<int>;

constexpr int INF = (1 << 30) - 1;
constexpr int64 INF64 = (1ll << 60) - 1;

#define rep(i, N) for(int i=0;i<(int)(N);++i)
#define fs first
#define sc second
#define e_b emplace_back
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	return os << "P(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "[";
	for (auto& e : v) os << e << ", ";
	return os << "]";
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& m) {
	os << "{" << endl;
	for (auto& e : m) os << "(" << e.first << ", " << e.second << ")" << endl;
	return os << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
	os << "{" << endl;
	for (auto& e : s) os << ", " << e << endl;
	return os << "}";
}

template<typename T>
vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
	return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

int64 gcd(int64 x, int64 y) {
	if (x == 0 || y == 0) return 0;
	int64 r;
	while ((r = y % x) != 0) {
		y = x;
		x = r;
	}
	return x;
}
int64 lcm(int64 x, int64 y) {
	if (x == 0 || y == 0) return 0;
	return x / gcd(x, y) * y;
}

// int dx[] = { -1, 0, 1, 0 };
// int dy[] = { 0, 1, 0, -1 };

void Main();
signed main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(30);
	Main();
}


/*----------------------------Insert from here!----------------------------*/



/*----------------------------Insert above here----------------------------*/


void Main() {
	int H, W; cin >> H >> W;
	vector<string> c(H);
	rep(i, H) cin >> c[i];

	using P = pair<int64, int64>;
	vector<P> v(W, P(INF, -INF));
	rep(j, W) rep(i, H) {
		if (c[i][j] == 'B') {
			v[j].fs = min(v[j].fs, (int64)i);
			v[j].sc = max(v[j].sc, (int64)i);
		}
	}
	int64 ans = 0;
	for(int64 j=0; j<W; ++j) {
		if (v[j].fs == INF || v[j].sc == -INF) continue;
		int64 n1 = 0, n2 = 0;
		for (int64 k = j; k < W; ++k) {
			if (v[k].fs == INF || v[k].sc == -INF) continue;
			else {
				n1 = max(n1, (k - j) + max(abs(v[k].fs - v[j].fs), abs(v[k].sc - v[j].fs)));
				n2 = max(n2, (k - j) + max(abs(v[k].fs - v[j].sc), abs(v[k].sc - v[j].sc)));
			}
		}
		ans = max({ ans, n1, n2 });
	}

	cout << ans << endl;
}


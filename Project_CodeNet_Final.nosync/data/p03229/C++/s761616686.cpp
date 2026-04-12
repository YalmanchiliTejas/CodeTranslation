#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
using vvint = vector<vint>;
using vvvint = vector<vvint>;
using vdouble = vector<double>;
using vvdouble = vector<vdouble>;
using vvvdouble = vector<vvdouble>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
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
constexpr int mod2 = 998244353;
template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) { return (a > b && (a = b, true)); }
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return (a < b && (a = b, true)); }

template<typename T>
vector<T> makeVector(size_t a, T b) { return (vector<T>(a, b)); }
template<typename... Ts>
auto makeVector(size_t a, Ts... ts) { 
	return (vector<decltype(makeVector(ts...))>(a, makeVector(ts...)));
}

template<typename T>
bool isin(T y, T x, T h, T w) { return (0 <= y && 0 <= x && y < h && x < w); }
template<typename T>
bool isin1(T y, T x, T h, T w) { return (0 < y && 0 < x && y <= h && x <= w); }

template<typename T>
ostream& operator <<(ostream &os, vector<T> &v) {
	if (v.size()) {
		os << v[0];
		for (int i = 1; i < v.size(); i++) os << " " << v[i];
	}
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


void Main() {
	ll N; cin >> N;
	vll A(N); cin >> A;
	sort(begin(A), end(A));

	if (N & 1) {
		ll sum1l = 0, sum1r = 0;
		for (int i = 0; i < N/2; i++) sum1l += 2*A[i];
		sum1r += A[N/2];
		sum1r += A[N/2+1];
		for (int i = N/2+2; i < N; i++) sum1r += 2*A[i];
		
		ll sum2l = 0, sum2r = 0;
		for (int i = 0; i < N/2-1; i++) sum2l += 2*A[i];
		sum2l += A[N/2-1];
		sum2l += A[N/2];
		for (int i = N/2+1; i < N; i++) sum2r += 2*A[i];

		cout << max(sum2r-sum2l, sum1r-sum1l) << endl;
	} else {
		ll suml = 0, sumr = 0;
		for (int i = 0; i < N/2-1; i++) suml += 2*A[i];
		suml += A[N/2-1];
		sumr += A[N/2];
		for (int i = N/2+1; i < N; i++) sumr += 2*A[i];
		cout << sumr-suml << endl;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(20);
	Main();
	return (0);
}

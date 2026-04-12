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
bool isin(T y, T x, T h, T w) { return (0 <= y && 0 <= x && y < h && x < w); }
template<typename T>
bool isin1(T y, T x, T h, T w) { return (0 < y && 0 < x && y <= h && x <= w); }

template<typename T>
ostream& operator <<(ostream &os, vector<T> &v) {
	os << v[0];
	for (int i = 1; i < v.size(); i++) os << " " << v[i];
	return (os);
}

template<typename T>
istream& operator >>(istream &is, vector<T> &v) {
	for (auto &u : v) is >> u; return (is);
}

template<typename T1, typename T2>
istream& operator >>(istream &is, pair<T1, T2> &p) {
	return (is >> p.first >> p.second);
}


void Main() {
	int N; cin >> N;
	vll S(N); cin >> S;

	vvll suml(N), sumr(N);
	for (int i = 1; i < N; i++) {
		suml[i].push_back(0);
		for (int j = i; j < N; j += i) {
			suml[i].push_back(S[j] + suml[i].back());
		}
		sumr[i].push_back(0);
		for (int j = N-i-1; j >= 0; j -= i) {
			sumr[i].push_back(S[j] + sumr[i].back());
		}
	}
	
	ll maxv = 0;
	for (ll A = 2; A < N-1; A++) {
		ll iA = N-1-A;
		//divの約数列挙
		vll divisor;
		for (ll i = 1; i*i <= iA; i++) {
			if (iA % i == 0) {
				divisor.push_back(i);
				if (i != iA/i) divisor.push_back(iA/i);
			}
		}

		for (auto &d : divisor) {
			if (d < A && (iA < A || A%d != 0)) {
				//cout << A << " " << d << endl;
				chmax(maxv, suml[d][iA/d] + sumr[d][iA/d]);
			}
		}
	}

	cout << maxv << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(20);
	Main();
	return (0);
}

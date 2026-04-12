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

template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) { return (a > b && (a = b, true)); }
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return (a < b && (a = b, true)); }

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
	vint S(N); cin >> S;
	vint T(N); cin >> T;
	vector<ull> U(N); cin >> U;
	vector<ull> V(N); cin >> V;
	vector<vector<ull>> ans(N, vector<ull>(N, 0));
	
	for (ull b = 0; b < 64; b++) {
		
		vint colnum(N, 0);
		vint rownum(N, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ull valr = (U[i]>>b)&1, valc = (V[j]>>b)&1;
				if (S[i] == 0 && valr == 1) ans[i][j] |= 1llu << b;
				if (T[j] == 0 && valc == 1) ans[i][j] |= 1llu << b;
				if (valr == valc) {
					ans[i][j] &= ~(1llu << b);
					ans[i][j] |= (valr << b);
				}
				if (S[i] == 0 && valr == 0 && !((ans[i][j]>>b)&1)) rownum[i]++;
				if (T[j] == 0 && valc == 0 && !((ans[i][j]>>b)&1)) colnum[j]++;
			}
		}

		for (int i = 0; i < N; i++) {
			if (!((U[i]>>b)&1) || !S[i]) continue;
			bool x = false;
			for (int j = 0; j < N; j++) {
				x |= ((ans[i][j]>>b) & 1);
			}
			if (x) continue;
			int j;
			for (j = 0; j < N; j++) {
				if (colnum[j] > 1) {
					ans[i][j] |= (1llu<<b);
					colnum[j]--;
					break;
				}
			}
		}

		for (int j = 0; j < N; j++) {
			if (!((V[j]>>b)&1) || !T[j]) continue;
			bool x = false;
			for (int i = 0; i < N; i++) {
				x |= ((ans[i][j]>>b) & 1);
			}
			if (x) continue;
			int i;
			for (i = 0; i < N; i++) {
				if (rownum[i] > 1) {
					ans[i][j] |= (1llu<<b);
					rownum[i]--;
					break;
				}
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		ull x = 0;
		if (S[i] == 0) x = numeric_limits<ull>::max();
		for (int j = 0; j < N; j++) {
			if (S[i]) x |= ans[i][j];	
			else x &= ans[i][j];
		}
		if (x != U[i]) { cout << -1 << el; return; }
	}

	for (int j = 0; j < N; j++) {
		ull x = 0;
		if (T[j] == 0) x = numeric_limits<ull>::max();
		for (int i = 0; i < N; i++) {
			if (T[j]) x |= ans[i][j];	
			else x &= ans[i][j];
		}
		if (x != V[j]) { cout << -1 << el; return; }
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i][0];
		for (int j = 1; j < N; j++) {
			cout << " " << ans[i][j];
		}
		cout << el;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(20);
	Main();
	return (0);
}

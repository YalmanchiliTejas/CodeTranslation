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

int main() {
	string S;
	ll K; cin >> S >> K;
	ll dp[105][5][2] = {};
	
	dp[0][0][0] = 1;
	int N = S.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			int val = S[i] - '0';

			if (val == 0) dp[i+1][j][0] += dp[i][j][0];
			else dp[i+1][j][1] += dp[i][j][0];
			dp[i+1][j][1] += dp[i][j][1];

			if (val > 0) {
				dp[i+1][j+1][1] += (val-1) * dp[i][j][0];
				dp[i+1][j+1][0] += dp[i][j][0];
			}
			dp[i+1][j+1][1] += 9 * dp[i][j][1];
		}
	}
	cout << dp[N][K][0] + dp[N][K][1] << endl;
	return (0);
}
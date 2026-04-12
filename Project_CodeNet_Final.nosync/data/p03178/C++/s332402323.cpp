#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i= (a); i<((int)b); ++i)
#define RFOR(i,a) for(int i=(a); i >= 0; --i)
#define FOE(i,a) for(auto i : a)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v,x) (std::find(v.begin(), v.end(), x) != v.end())
#define BIT_ON(bit, i) (bit & (1LL << i))
#define BIT_COUNT(bit) (__builtin_popcount(bit))

typedef long long LL;
template<typename T> using V = std::vector<T>;
template<typename T> using VV = std::vector<std::vector<T>>;
template<typename T> using VVV = std::vector<std::vector<std::vector<T>>>;
template<typename T> using VVVV = std::vector<std::vector<std::vector<std::vector<T>>>>;

template<class T> inline T ceil(T a, T b) { return (a + b - 1) / b; }
template<class T> inline void print(T x) { std::cout << x << std::endl; }
template<class T> inline void print_vec(const std::vector<T> &v) { for (int i = 0; i < v.size(); ++i) {  if (i != 0) {std::cout << " ";} std::cout << v[i];} std::cout << "\n"; }
template<class T> inline void print_2vec(const std::vector<std::vector<T>> &v) { for (int i = 0; i < v.size(); ++i) { for (int j = 0; j < v[0].size(); ++j) { if (j != 0) { std::cout << " "; } std::cout << std::setw(13) << std::left << v[i][j]; } std::cout << "\n";}}
template<class T> inline bool inside(T y, T x, T H, T W) {return 0 <= y and y < H and 0 <= x and x < W; }
template<class T> inline double euclidean_distance(T y1, T x1, T y2, T x2) { return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }
template<class T> inline double manhattan_distance(T y1, T x1, T y2, T x2) { return abs(x1 - x2) + abs(y1 - y2); }
template<typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }
template<typename T> T &chmax(T &a, const T &b) { return a = std::max(a, b); }
template<class T> inline std::vector<T> unique(std::vector<T> v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); return v; }
// 初項s, 交差dのn個の数列の和
long long sum_of_arithmetic_progression(long long s, long long d, long long n) { return n * (2 * s + (n - 1) * d) / 2; }

const int INF = 1 << 30;
const double EPS = 1e-9;
const std::string YES = "YES", Yes = "Yes", NO = "NO", No = "No";
const std::vector<int> dy4 = {0, -1, 0, 1}, dx4 = {1, 0, -1, 0};
const std::vector<int> dy8 = { 0, -1, 0, 1, 1, -1, -1, 1 }, dx8 = { 1, 0, -1, 0, 1, 1, -1, -1 };

using namespace std;

int MOD = 1000000007;
string S;
int D;
VVV<int> dp;
int rec(int k, bool tight, int rest) {
	if (k >= S.size()) {
		return rest == 0;
	}

	if (dp[k][tight][rest] != -1) {
		return dp[k][tight][rest];
	}

	int ans = 0;
	int x = S[k] - '0';
	int upper = tight ? x : 9;
	FOR(i, 0, upper + 1) {
		(ans += rec(k + 1, tight && i == x, (rest + i) % D)) %= MOD;
	}

	return dp[k][tight][rest] = ans;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> S;
	cin >> D;

	dp.assign(S.size() + 1, VV<int>(2, V<int>(101, -1)));
	print((rec(0, true, 0) + MOD - 1) % MOD);

	return 0;
}
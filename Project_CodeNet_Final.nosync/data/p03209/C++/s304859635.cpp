#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()		// 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend()	// 降順ソート 例:sort(DESC(vec));
#define rep(i, n) for(int i = 0; i < (n); i++)
#define Rep(i, n) for(int i = 1; i < n; i++)
#define REP(i, vec) for(auto i = vec.begin(); i != vec.end(); ++i)

const int mod = 1000000007;
const int inf = (1 << 21);
const long long INF = 1LL << 60;

using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vii = vector<pair<int, int>>;
using vll = vector<pair<ll, ll>>;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline T GCD(T a, T b) { return b ? GCD(b, a % b) : a; }
template<class T> inline T LCM(T a, T b) { return (a + (b - 1)) / b; }

int round_int(int a, int b) { return (a + (b - 1)) / b; }

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

ll rec(ll n, ll x) {
	if (n == 0) return 1;

	ll len = (1LL << (n + 1)) - 3;
	ll num = (1LL << n) - 1;

	if (x == 1) return 0;
	else if (x <= len + 1) return rec(n - 1, x - 1);
	else if (x == len + 2) return num + 1;
	else if (x <= (len + 1) * 2) return num + 1 + rec(n - 1, x - len - 2);
	else return num * 2 + 1;
}

int main() {
	ll n, x;
	cin >> n >> x;

	cout << rec(n, x) << endl;
}
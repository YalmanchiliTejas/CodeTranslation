#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()		// 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend()	// 降順ソート 例:sort(DESC(vec));
#define rep(i, n) for(int i = 0; i < n; i++)
#define Rep(i, n) for(int i = 1; i < n; i++)
#define In(vec) rep(i, n) cin>>vec[i];
#define ANS(s) cout << s << endl
#define inc(a, b) cin >> a >> b;

const int mod = 1000000007;
const int inf = (int)1e9 + 7;
const long long INF = 1LL << 60;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vii;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll LCM(ll a, ll b) { return (a * b) / GCD(a, b); }
int round_int(int a, int b) { return (a + (b - 1)) / b; }


// 4,8方向に探索する際に用いる配列
//int dx[4] = { 0,  0, 1, -1 };
//int dy[4] = { 1, -1, 0,  0 };
//int dx[8] = { 1, 0, -1,  0, 1, -1, -1,  1 };
//int dy[8] = { 0, 1,  0, -1, 1,  1, -1, -1 };

// ────────────────────────────────────────────────────

int main() {
	int n;
	cin >> n;

	vi t(n);
	rep(i, n) cin >> t[i];

	sort(ASC(t));
	int max_ = t.back();

	vi yak;
	for (int i = max_; i >= 1; --i) {
		if (max_ % i == 0) yak.push_back(i);
	}
	sort(ASC(yak));

	int ans = 0;

	rep(i, n) {
		if (t[i] == max_) continue;

		for (int j = 0; j < yak.size(); ++j) {
			if (t[i] <= yak[j]) {
				ans += yak[j] - t[i];
				break;
			}
		}
	}
	cout << ans << endl;
}

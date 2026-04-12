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
typedef vector<ll> vl;
typedef vector<pair<int, int>> vii;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
int round_int(int a, int b) { return (a + (b - 1)) / b; }


// 4,8方向に探索する際に用いる配列
//int dx[4] = { 0,  0, 1, -1 };
//int dy[4] = { 1, -1, 0,  0 };
int dx[8] = { 1, 0, -1,  0, 1, -1, -1,  1 };
int dy[8] = { 0, 1,  0, -1, 1,  1, -1, -1 };

constexpr auto MAX = 100010;

// ────────────────────────────────────────────────────

int main()
{
	int r, g, b;
	cin >> r >> g >> b;

	if ((r * 100 + g * 10 + b) % 4 == 0)
	{
		ANS("YES");
	}
	else
	{
		ANS("NO");
	}
}
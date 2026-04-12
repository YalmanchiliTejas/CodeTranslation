#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()		// 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend()	// 降順ソート 例:sort(DESC(vec));
#define rep(i, n) for(i = 0; i < n; i++)
#define Rep(i, n) for(i = 1; i < n; i++)
#define Ans(s) cout << s << endl;

const int inf = (int)1e9 + 7;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }

typedef long long ll;

// 4,8方向に探索する際に用いる配列
//int dx[4] = { 0,  0, 1, -1 };
//int dy[4] = { 1, -1, 0,  0 };
//int dx[8] = { 1, 0, -1,  0, 1, -1, -1,  1 };
//int dy[8] = { 0, 1,  0, -1, 1,  1, -1, -1 };

constexpr auto MAX = 100010;

int main()
{
	int x, y, z;
	cin >> x >> y >> z;

	int ans = x / (y + z);

	if ((y + z) * ans + z > x) ans--;
	cout << ans << endl;
}
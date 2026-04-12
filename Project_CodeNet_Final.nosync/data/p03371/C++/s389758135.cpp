#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()		// 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend()	// 降順ソート 例:sort(DESC(vec));
#define rep(i, n) for(i = 0; i < n; i++)

const int inf = (int)1e9 + 7;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;

// 4,8方向に探索する際に用いる配列
//int dx[4] = { 0,  0, 1, -1 };
//int dy[4] = { 1, -1, 0,  0 };
//int dx[8] = { 1, 0, -1,  0, 1, -1, -1,  1 };
//int dy[8] = { 0, 1,  0, -1, 1,  1, -1, -1 };

int main()
{
	int a, b, ab, x, y;
	cin >> a >> b >> ab >> x >> y;

	int ans1 = a * x + b * y;


	int max_num = max(x, y);
	if (max_num % 2 == 1) max_num++;

	int ans2 = (ab * 2) * max_num;


	int min_num = min(x, y);

	int ans3 = ((ab * 2) * min_num) + (a * (x - min_num) + b * (y - min_num));

	cout << min({ ans1, ans2, ans3 }) << endl;
}

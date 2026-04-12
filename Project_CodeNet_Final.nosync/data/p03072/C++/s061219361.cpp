#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()		// 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend()	// 降順ソート 例:sort(DESC(vec));
#define rep(i, n) for(i = 0; i < n; i++)

const int inf = (int)1e9 + 7;
const long long INF = 1LL << 60;

typedef long long ll;

template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
int N;
ll h[100010];

// DP テーブル
ll dp[100010];
*/

int main()
{
	int ans = 0;
	int max_ = 0;
	int N; cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
		max_ = max(max_, H[i]);

		if (H[i] >= max_) ans++;
	}
	cout << ans << endl;
}

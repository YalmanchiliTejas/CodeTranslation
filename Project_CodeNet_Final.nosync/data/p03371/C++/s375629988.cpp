template<class T> inline void chmin(T & a, T b) { if (a > b) a = b; }

#define rep(i, n) for(int i=0; i<n; i++)
#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
	const long long MAX = 100000;

	long long res = (1LL << 30);
	long long ab, a, b;

	// 必要なA, Bピザを必要枚数X, Y分買うのに最小で何円で買えるかシミュレート
	// ABピザを0~10万枚まで全探索する
	rep(i, MAX+1) {
		ab = i * 2 * C; // ABピザをi枚買った時の価格
		a = max(0LL, X - i) * A; // 足りない分のAピザの価格
		b = max(0LL, Y - i) * B; // 足りない分のBピザの価格
		chmin(res, ab + a + b);
	}

	cout << res << endl;

}

int main(void) {
	solve();
	return 0;
}
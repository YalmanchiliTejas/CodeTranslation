#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int INF = 1e9 + 7, MOD = 1e9 + 7;
const long long LINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	long long ans = 0;
	if (a + b > c * 2) { //cを2回引いたほうが安い
		while (x > 0 && y > 0) { //xもyもまだ残っている間c*2で引いていく
			x--, y--;
			ans += c * 2;
		}
		if (x > 0) { //xがまだ残ってる
			if (a < c * 2) { //c*2を引くよりaを引く方が安い
				while (x > 0) { // xが残っている間aで引く
					x--, ans += a;
				}
			} else { //c*2で引いた方が安い
				while (x > 0) { // xが残っている間c*2で引く
					x--, ans += c * 2;
				}
			}
		}
		if (y > 0) { //yがまだ残ってる
			if (b < c * 2) { //c*2を引くよりbを引く方が安い
				while (y > 0) { //yが残っている間bで引く
					y--, ans += b;
				}
			} else { //c*2で引いた方が安い
				while (y > 0) { //yが残っている間c*2で引く
					y--, ans += c * 2;
				}
			}
		}
	} else {
		while (x > 0) { //a+b<c*2なのでそれぞれをa,bで引いていく
			x--, ans += a;
		}
		while (y > 0) {
			y--, ans += b;
		}
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll unsigned long long

const ll MOD = 1000000000000000000;

int main() {
	//入力
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;

	//処理
	ll ans = INT_MAX;
	int a1, b1, c1;
	a1 = b1 = 0;
	c1 = (max(x,y) - a1) * 2;
	ans = c1 * c;
	//
	for (int a1 = 0;a1 <= x;++a1) {
		c1 = (x - a1) * 2;
		b1 = max(0, y - c1 / 2);
		ll z = a1 * a + b1 * b + c1 * c;
		if (z < ans) ans = z;
	}

	//出力
	cout << ans << endl;

	return 0;
}
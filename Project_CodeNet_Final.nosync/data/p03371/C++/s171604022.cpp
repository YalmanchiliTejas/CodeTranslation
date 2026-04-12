#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// 最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// 最小公倍数
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}*/

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	ll ans = 0;

	if (a + b >= 2 * c) {
		while (x > 0 && y > 0) {
			x--;
			y--;
			ans += 2 * c;
		}
		if (x > 0) {
			if (a < 2 * c) {
				ans += x * a;
			}
			else {
				ans += x * 2 * c;
			}
		}
		else if(y > 0) {
			if (b < 2 * c) {
				ans += y * b;
			}
			else {
				ans += y * 2 * c;
			}
		}
	}
	else {
		ll tx = x;
		ll ty = y;
		if (tx > 0) {
			if (a < 2 * c) {
				ans += tx * a;
			}
			else {
				ans += tx * 2 * c;
				ty -= tx;
			}
		}
		if (ty > 0) {
			if (b < 2 * c) {
				ans += ty * b;
			}
			else {
				ans += ty * 2 * c;
			}
		}

		ll tmp = 0;

		if (y > 0) {
			if (b < 2 * c) {
				tmp += y * b;
			}
			else {
				tmp += y * 2 * c;
				x -= y;
			}
		}
		if (x > 0) {
			if (a < 2 * c) {
				tmp += x * a;
			}
			else {
				tmp += x * 2 * c;
				y -= x;
			}
		}

		ans = min(ans, tmp);
	}

	cout << ans << endl;

	return 0;
}
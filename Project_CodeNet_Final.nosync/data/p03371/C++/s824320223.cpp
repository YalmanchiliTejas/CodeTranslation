#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	int a, b, c, x, y;
	int ans;
	cin >> a >> b >> c >> x >> y;
	if ((a + b) / 2 >= c) {
		int ans1, ans2;
		int x1;

		ans1 = 2 * min(x, y) * c;
		x1 = min(x, y);
		x -= x1;
		y -= x1;

		ans = ans1;

	}
	else {
		ans = a * x + b * y;
		x = 0;
		y = 0;
	}
	//	cout << ans << endl;

	if (a >= 2 * c) {
		ans += 2 * x * c;
	}
	else {
		ans += a * x;
	}
	if (b >= 2 * c) {
		ans += 2 * y * c;
	}
	else {
		ans += b * y;
	}
	cout << ans << endl;

}
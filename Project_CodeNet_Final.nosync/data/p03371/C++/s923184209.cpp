#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
using namespace std;

typedef long long ll;
#define modulo 1000000007 // 10^9 + 7
#define MAX 1000000000 // 10^9


int main() {
	int price[3];
	int x, y;
	cin >> price[0] >> price[1] >> price[2] >> x >> y;
	
	int ans = 0;
	int k = min(x, y);


	if (2 * price[2] <= price[0] + price[1]) {
		ans += 2 * price[2] * k;
	}
	else {
		ans += price[0] * k;
		ans += price[1] * k;
	}

	x -= k;
	y -= k;

	if (x == 0) {
		if (2 * price[2] < price[1]) ans += 2 * price[2] * y;
		else ans += price[1] * y;
	}
	else {
		if (2 * price[2] < price[0]) ans += 2 * price[2] * x;
		else ans += price[0] * x;
	}

	cout << ans << endl;

	return 0;
}
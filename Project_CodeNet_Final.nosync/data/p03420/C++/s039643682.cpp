#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <random>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, ans, x, y, v;
	cin >> n >> k;

	ans = 0;
	for (i = k + 1; i <= n; i++) {
		x = (n + 1) / i;
		y = (n + 1) % i;

		v = x * (i - k) + max(0LL, y - k);
		if (k == 0) v--;
		ans += v;

		//cout << i << " " << v << "\n";
	}
	cout << ans << "\n";

	return 0;
}

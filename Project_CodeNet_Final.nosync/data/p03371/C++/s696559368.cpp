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

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long a, b, c, i, j, k, x, y, ans, p;
	cin >> a >> b >> c >> x >> y;
	ans = 1LL << 61;
	for (i = 0; i <= max(x, y) * 3; i+=2) {
		p = i * c + max(0LL, x - i / 2) * a + max(0LL, y - i / 2) * b;
		ans = min(ans, p);
	}
	cout << ans << "\n";

	return 0;
}

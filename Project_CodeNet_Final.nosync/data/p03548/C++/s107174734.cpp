#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
const long long INF = 1e9 + 7;
using namespace std;
map<int, int> mp;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int x, y, z;
	cin >> x >> y >> z;
	int ans = 0;
	for (int i = 1; i < 50001; i++) {
		int tmp = y * i + z * (i + 1);
		if (tmp > x) {
			ans = i - 1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
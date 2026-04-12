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

vector<long long> a;
long long n;

map<pair<int, int>, long long> dp;

long long solve(int step, int x) {
	if (x * 2 - 1 > step + 1) return -(1LL << 60);
	if (dp.find({ step, x }) != dp.end()) return dp[{step, x}];
	if (x == 0) return 0;

	long long ans = -(1LL << 60);
	if (x == 1) {
		ans = max(ans, a[step]);
		if (step > 0) ans = max(ans, solve(step - 1, x));
	}
	else {
		if (step >= 2) ans = max(ans, a[step] + solve(step - 2, x - 1));
		ans = max(ans, solve(step - 1, x));
	}

	dp[{step, x}] = ans;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long i, j, k, ans, x;
	cin >> n;
	a.resize(n);
	for (i = 0; i < n; i++) cin >> a[i];
	x = n / 2;

	ans = solve(n - 1, x);
	cout << ans << "\n";

	return 0;
}

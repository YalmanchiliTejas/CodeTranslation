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

#define MAXN 51
long long n, x, i, j, k, ans;
vector<long long> sz(MAXN), p(MAXN);

long long solve(long long n, long long x) {
	if (x <= 0) return 0;
	if (n == 0) return 1;
	if (x >= sz[n]) return p[n];

	long long a = 0;
	if (x <= 1 + sz[n - 1]) a = solve(n - 1, x - 1);
	else {
		a = 1 + p[n - 1] + solve(n - 1, x - 2 - sz[n - 1]);
	}
	return a;	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	sz[0] = 1; p[0] = 1;
	for (i = 1; i < MAXN; i++) {
		sz[i] = 3 + sz[i - 1] * 2;
		p[i] = p[i - 1] * 2 + 1;
	}

	cin >> n >> x;
	ans = solve(n, x);

	cout << ans << "\n";

	return 0;
}

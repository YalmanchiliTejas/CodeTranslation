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

#define MAXN 3005

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, s, ans, MOD = 998244353;
	cin >> n >> s;
	vector<long long> a(n), ct(MAXN, 0), sum(MAXN, 0);
	for (i = 0; i < n; i++) cin >> a[i];

	ans = 0;
	for (i = 0; i < n; i++) {
		for (j = s - a[i]; j >= 1; j--) {
			ct[j + a[i]] = (ct[j + a[i]] + ct[j]) % MOD;
			sum[j + a[i]] = (sum[j + a[i]] + sum[j]) % MOD;
		}

		// add self (standalone)
		ct[a[i]] = (ct[a[i]] + 1) % MOD;
		sum[a[i]] = (sum[a[i]] + i) % MOD;

		// add all occurrence without current one
		ans = (ans + sum[s] + ct[s]) % MOD;
	}

	cout << ans << "\n";

	return 0;
}

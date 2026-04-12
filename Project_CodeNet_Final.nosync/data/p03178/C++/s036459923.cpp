//MADE BY Y_is_sunshine;
//#include <bits/stdc++.h>
//#include <memory.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define pb push_back
#define pf push_front
#define INF 0x3f3f3f3f
#define MAXN (int) 1e6 + 7
#define all(a) a.begin(), a.end()

typedef long long ll;

const ll mod = 1e9 + 7;
const double PI = acos(-1);

using namespace std;

int N, M, K, T;

ll dp[100004][105];

int a[100004];

ll k;

ll dfs(int pos, int sum, bool limit) {
	if (pos == -1)
		return !sum;
	if (!limit && ~dp[pos][sum])
		return dp[pos][sum];
	int up = limit ? a[pos] : 9;

	ll ans = 0;
	for (int i = 0; i <= up; i++) {
		ans += dfs(pos - 1, (sum + i) % k, limit && i == up);
		ans %= mod;
	}

	if (!limit)
		dp[pos][sum] = ans;
	return ans;
}

signed main(void) {

#ifdef Sunshine
	freopen("data.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	string s;
	cin >> s >> k;
	
	for (int i = 0; i < s.size(); i++) {
		a[i] = s[s.size() - i - 1] - '0';
	}

	
	cout << (mod + dfs(s.size() - 1, 0, true) - 1) % mod;













#ifdef Sunshine
	freopen("CON", "r", stdin);
	system("pause");
#endif
	return 0;
}
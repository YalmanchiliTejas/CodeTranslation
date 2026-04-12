// Ala be zekrellah tatmaenolgholoob ...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 100+9;
const ll mod = 1e9+7;

set <int> st;
map <int,int> mp;
ll dp[maxn][maxn];
int h[maxn], val[maxn], len[maxn];

ll cal (ll x, ll p) {
	if (p == 0)
		return 1;
	ll res = cal(x, p / 2);
	res = (res * res) % mod;
	if (p % 2)
		res = res * x % mod;
	return res;
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, num = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		st.insert(h[i]);
	}
	int last = 0;
	for (auto x : st) {
		val[num] = x;
		len[num] = x - last;
		mp[x] = num;
		num++;
		last = x;
	}
	// base
	dp[0][0] = 2;
	for (int i = 1; i <= mp[h[0]]; i++) {
		if (val[i] == 1)
			continue;
		ll cur = cal(2, h[0] - val[i] + 1) * (cal(2, len[i]) - 1) % mod;
		if (i == 1)
			cur = cal(2, h[0] - val[i]) * (cal(2, len[i]) - 2) % mod;
		cur = (cur + mod) % mod;
		dp[0][i] = cur;
	}
	for (int i = 1; i < n; i++) {
		// dp[i][0]
		dp[i][0] = dp[i - 1][0] * 2 % mod;
		for (int t = mp[h[i]] + 1; t < maxn; t++)
			dp[i][0] = (dp[i][0] + dp[i - 1][t] * 2 % mod) % mod;
		// dp[i][a]
		for (int t = 1; t <= mp[h[i]]; t++)
			dp[i][t] = dp[i - 1][t] * cal(2, max(h[i] - h[i - 1], 0)) % mod;
		if (h[i] <= h[i - 1])
			continue;
		ll f = dp[i - 1][0];
		for (int t = mp[h[i - 1]] + 1; t <= mp[h[i]]; t++)
			dp[i][t] = f * cal(2, h[i] - val[t] + 1) % mod * (cal(2, len[t]) - 1) % mod;
	}
	// ans
	ll res = 0;
	for (int i = 0; i < maxn; i++)
		res = (res + dp[n - 1][i]) % mod;
	cout << res << "\n";
}


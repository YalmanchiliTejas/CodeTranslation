#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int a[10004][105][2];
string s;
int k, d;
int mod = 1e9 + 7;
int dp(int pos, int m, int f)
{
	if (pos == s.size()) {
		if (m == 0)
			return 1;
		return 0;
	}
	if (a[pos][m][f] != -1)
		return a[pos][m][f];
	if (!f)
	{
		a[pos][m][f] = 0;
		for (int i = 0; i <= 9; ++i)
			a[pos][m][f] = (a[pos][m][f] + (dp(pos + 1, ((m - i) % d + d) % d, f))) % mod;
	}
	else
	{
		a[pos][m][f] = 0;
		for (int i = 0; i < (s[pos] - '0'); ++i)
			a[pos][m][f] = (a[pos][m][f] + dp(pos + 1, ((m - i) % d + d) % d, 0)) % mod;
		a[pos][m][f] = (a[pos][m][f] + dp(pos + 1, ((m - (s[pos] - '0')) % d + d) % d, 1)) % mod;
	}
	return a[pos][m][f];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	memset(a, -1, sizeof(a));
	cin >> s;
	cin >> d;
	cout << ((dp(0, 0, 1) - 1) % mod + mod) % mod;
}
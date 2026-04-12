#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e3 + 10;

ll dp[N][N][2];

ll solve(int l, int r, bool player, vector<int> &a, ll s)
{
	if(l > r)
		return 0;

	ll &ans = dp[l][r][player];

	if(ans != -1)
		return ans;

	ans = s - solve(l + 1, r, !player, a, s - a[l]);
	ans = max(ans, s - solve(l, r - 1, !player, a, s - a[r]));

	return ans;
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	ll s = 0;

	for(int &x : a)
	{
		cin >> x; 
		s += x;
	}

	memset(dp, -1, sizeof(dp));

	ll f = solve(0, n - 1, 1, a, s);

	cout << 2ll * f  - s << endl;

	return 0;
}
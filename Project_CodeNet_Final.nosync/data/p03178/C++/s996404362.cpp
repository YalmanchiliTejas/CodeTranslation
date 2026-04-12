#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define sz size()

const int mod = 1e9 + 7;

void add(int &x, int y)
{
	x += y;
	if(x >= mod)
		x -= mod;
}

signed main()
{
	ios::sync_with_stdio(0);
	int i, j, n, d;
	string k;

	cin >> k >> d;
	n = k.sz;

	vector<vector<int>> dp(d, vector<int>(2));
	dp[0][0] = 1;

	for(i=0;i<n;++i)
	{
		vector<vector<int>> newdp(d, vector<int>(2));
		for(int rem=0;rem<d;++rem)
		{
			// can == true
			for(int dig=0;dig<=9;++dig)
				add(newdp[(rem+dig)%d][1], dp[rem][1]);

			// can == false
			for(int dig=0;dig<k[i]-'0';++dig)
				add(newdp[(rem+dig)%d][1], dp[rem][0]);
			add(newdp[(rem+k[i]-'0')%d][0], dp[rem][0]);
		}

		dp = newdp;
	}

	int ans = (dp[0][0] + dp[0][1]) % mod;
	ans--;
	if(ans == -1)
		ans = mod - 1;
	
	cout << ans << "\n";

	return 0;
}
#include <bits/stdc++.h>

#define SZ(x) (((int)x.size()))
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

using namespace std;

const int mod = 998244353, maxn = 3*1000+10;
ll dp[maxn], ans;
int n, s, a;

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		for (int j = s; j >= a; j--)
		{
			if (j == s)
			{
				if (j - a == 0)
					ans += (ll)(n - i) * (i + 1);
				else
					ans += (ll)(n - i) * dp[j - a];
				ans %= mod;
			}
			if (j - a == 0)
				dp[j] += i + 1;
			else
				dp[j] += dp[j - a];
			dp[j] %= mod;
		}
	}
	cout << ans;
	return 0;
}

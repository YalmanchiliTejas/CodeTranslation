// In The Name Of Allah
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e12;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
const ll mod = 1e9 + 7;
 
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const ll M = 26 + 10;
const ll N = 30 * 100 + 10;

ll dp[2][N][N] , a[N];

ll solve(int t, int l, int r)
{
	if(l == r)
	{
		if(t == 0)
		{
			return a[l];
		}
		else
		{
			return -a[l];
		}
	}
	if(dp[t][l][r] != -1)
		return dp[t][l][r];
	if(t == 0)
	{
		return dp[t][l][r] = max(solve(1 - t, l + 1, r) + a[l], solve(1 - t, l, r - 1) + a[r]);
	}
	else
	{
		return dp[t][l][r] = min(solve(1 - t, l + 1, r) - a[l], solve(1 - t, l, r - 1) - a[r]);
	}
}

int main()	
{
	faster();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[k][i][j] = -1;
			}
		}
	}
	cout << solve(0, 0, n - 1) << endl;
}
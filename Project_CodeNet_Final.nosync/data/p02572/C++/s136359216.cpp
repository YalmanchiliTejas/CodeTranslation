
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define int long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
int pallindr(string s, int i, int j)
{
	while (i <= j)
	{
		if (s[i] != s[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}
int dp[1001][1001];
int pallindrome_partitioning(string s, int i, int j)
{
	if (i >= j)
		return 0;
	if (pallindr(s, i, j))
	{
		return dp[i][j] = 0;

	}

	if (dp[i][j] != -1)
		return dp[i][j];

	int ans = INT_MAX;
	for (int k = i; k < j; k++)
	{
		int left, right;
		if (dp[i][k] != -1)
			left = dp[i][k];
		else
		{
			left = pallindrome_partitioning(s, i, k);
			dp[i][k] = left;
		}

		if (dp[k + 1][j] != -1)
			right = dp[k + 1][j];
		else
		{
			right = pallindrome_partitioning(s, k + 1, j);
			dp[k + 1][j] = right;
		}

		int xx = left + right + 1;
		ans = min(ans, xx);
	}
	return dp[i][j] = ans;


}

int32_t main()
{
	std::ios::sync_with_stdio(false);


	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int res = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum = (sum + a[i] + mod) % mod;

	for (int i = n - 1; i >= 0; i--)
	{
		sum = (sum - a[i]) % mod;
		res = (res + (a[i] * sum) % mod + mod) % mod;

	}
	cout << (res + mod) % mod << endl;
	return 0;
}

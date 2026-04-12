#pragma region templates 


//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<math.h>
#include<string>
#define all(v) v.begin(),v.end()
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define REV(x) reverse(x.begin(),x.end())
#define pi pair<int,int>
#define SORT(v) sort(all(v))
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

ll gcd(ll a, ll b) { if (a == 0)return(b); else return(gcd(b % a, a)); }
int modularexpo(ll a, ll b, ll c)
{
	if (a == 0)
	{
		return 0;
	}
	if (b == 0)
	{
		return 1;
	}
	else {
		if (b % 2 == 0)
		{
			long smallans = modularexpo(a, b / 2, c);
			int ans = ((smallans % c) * (smallans % c)) % c;
			return (ans + c) % c;
		}
		else {
			long smallans = modularexpo(a, b - 1, c);
			long ans = a % c;
			ans = ((ans % c) * (smallans % c)) % c;
			return (ans + c) % c;
		}
	}
}
long combination(int n, int r)
{
	long long ans = 1;
	r = r > n - r ? n - r : r;
	int j = 1;
	for (; j <= r; j++, n--)
	{
		if (n % j == 0)
		{
			ans *= n / j;
		}
		else
			if (ans % j == 0)
			{
				ans = ans / j * n;
			}
			else
			{
				ans = (ans * n) / j;
			}
	}
	return ans;
}
int binary(int* arr, int l, int r, int x)
{
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (arr[mid] == x)
		{
			return mid;
		}
		else if (arr[mid] < x)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return -1;
}
#pragma endregion
ll recur(int* arr, int n, int i, int j,int flag, ll*** dp)
{
	if (i == j && flag == 0)
	{
		return arr[i];
	}
	else if (i == j && flag == 1)
	{
		return (arr[i] * -1);
	}
	if (dp[flag][i][j] != -1)
	{
		return dp[flag][i][j];
	}
	else {
		if (flag == 0)
		{
			ll ans = max(recur(arr, n, i + 1, j, flag ^ 1, dp) + arr[i], recur(arr, n, i, j-1, flag ^ 1, dp) + arr[j]);
			 dp[flag][i][j] = ans;
			 return dp[flag][i][j];
		}
	
		else {
			ll ans = min(recur(arr, n, i + 1, j, flag ^ 1, dp) - arr[i], recur(arr, n, i, j - 1, flag ^ 1, dp)-arr[j]);
			dp[flag][i][j] = ans;
			return dp[flag][i][j];
		}
	
	}

}
int main()
{
	int n;
	std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	ll*** dp = new ll * *[2];
	for (int i = 0; i < 2; i++)
	{
		dp[i] = new ll * [n];
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = new ll[n];
			for (int k = 0; k < n; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	std::cout << recur(arr, n, 0, n - 1, 0, dp);

	return 0;
}

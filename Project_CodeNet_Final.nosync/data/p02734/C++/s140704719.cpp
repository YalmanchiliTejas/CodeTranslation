#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
#define pii pair<int , int>
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
int a[3005];
int dp[3005][3005];
int mod = 998244353;
int add(int a , int b)
{
	return (a + b) % mod;
}
int mult(int a,  int b)
{
	return a * (ll)b % mod;
}
void Add(int &a , int b)
{
	a = add(a , b);
}
int main()
{
	int n , s;
	cin >> n >> s;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(i)
		{
			for(int j = 1; j <= s - a[i]; j++)
				Add(dp[i][j + a[i]] , dp[i - 1][j]);
			for(int j = 1; j <= s; j++)
				Add(dp[i][j] , dp[i - 1][j]);
		}
		Add(dp[i][a[i]] , i + 1);
		Add(ans , dp[i][s]);
	}
	cout << ans;
}

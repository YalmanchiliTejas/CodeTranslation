//I forgot you...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)2e5 + 3;
const int infint = (int)1e9 + 3;
const ll inf = (ll)1e18;
int n, m, ans, mika = infint, dp[MAXN], part[MAXN];
string s;
int add(int a, int b)
{
	int c = a + b;
	if(c >= MOD)
		c -= MOD;
	if(c < 0)
		c += MOD;
	return c;
}
int mul(int a, int b)
{
	int c = 1LL * a * b % MOD;
	return c;
}
void find_mika()
{
	mika = n - 1;
	if(n % 2 == 1)
		mika--;
	if(s[0] == 'R')
	{
		bool first = 0;
		int ted = 0;
		for (int i = 0; i < m; i++)
			if(s[i] == 'R')
				ted++;
			else
			if(s[i] == 'B' && ted > 0)
			{
				if(ted % 2)	
					mika = min(mika, ted);
				else
				if(first == 0)
					mika = min(mika, ted + 1);
				first = 1;
				ted = 0;
			}
	}
	else
	{
		int ted = 0;
		bool first = 0;
		for (int i = 0; i < m; i++)
			if(s[i] == 'B')
				ted++;
			else
			if(s[i] == 'R' && ted > 0)
			{
				if(ted % 2)
					mika = min(mika, ted);
				else
				if(first == 0)
					mika = min(mika, ted + 1);
				first = 1;
				ted = 0;
			}
	}
}
int getzarib(int kaman)
{
	int emp = n - kaman;
	if(emp == 0)
		return 1;
	else
		return n - emp;
}
int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	bool flg = 1;
	for (int i = 1; i < m; i++)
		if(s[i] != s[0])	
			flg = 0;
	if(flg)
	{
		dp[0] = 1, dp[1] = 1, dp[2] = 2;
		for (int i = 3; i <= n; i++)
			dp[i] = add(dp[i - 1], dp[i - 2]);
		
		ans = dp[n];
		if(n >= 2)
			ans = add(ans, dp[n - 2]);
		cout << ans;
		return 0;
	}
	find_mika();
	//cout << mika << endl;

	dp[0] = 1;
	part[0] = 1;
	for (int i = 2; i <= n; i += 2)
	{
		dp[i] = part[i - 2];
		if(i - mika - 3 >= 0)
			dp[i] = add(dp[i], -part[i - mika - 3]);
		part[i] = add(part[i - 2], dp[i]);
	}
	ans = add(ans, dp[n]);
	for (int i = 1; i <= mika; i += 2)
		if(i != n - 2 && i != n)
			ans = add(ans, mul(getzarib(i), dp[n - i - 1]));
		else
		if(i == n)
			ans = add(ans, 1);
	cout << ans;
}




/*
8 10
RRRRBRRBBR
*/

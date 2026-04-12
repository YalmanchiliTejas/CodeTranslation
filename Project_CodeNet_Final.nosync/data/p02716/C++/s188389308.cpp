// Beginner162.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
typedef  long long ll;
using namespace std;

bool has7(int n)
{
	while (n > 0)
	{
		int c = n % 10;
		if (c == 7) return true;
		n /= 10;
	}
	return false;
}

int gcd(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main()
{
	//A
	/*int n;
	cin >> n;
	bool has = has7(n);
	cout << (has ? "Yes" : "No");*/

	//B
	/*int n;
	cin >> n;

	ll result = 0;
	for (int i = 1; i <=n; ++i)
	{
		if (i % 3 != 0 && i % 5 != 0)
		{
			result += i;
		}
	}
	cout << result;*/
	
	//C
	/*int k;
	cin >> k;

	ll result = 0;
	vector<vector<int>> v(k + 1, vector<int>(k + 1, 0));
	for (int i = 1; i <= k; ++i)
	{
		for (int j = i; j <= k; ++j)
		{
			int g = gcd(i, j);
			v[i][j] = g;
			v[j][i] = g;
		}
	}
	
	for (int i = 1; i <=k; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			int ij = v[i][j];
			
			for (int l = 1; l <= k; ++l)
			{
				int ijl = v[ij][l];
				result += ijl;
			}
		}
	}
	
	cout << result;*/

	//D
	/*int n;
	string s;
	cin >> n >> s;

	ll result = 0;

	vector<vector<int>> count(n, vector<int>(3, 0));
	for (int i = n-1; i >=0; --i)
	{
		if (s[i] == 'R') count[i][0]++;
		else if (s[i] == 'G') count[i][1]++;
		else count[i][2]++;

		if (i < n-1)
		{
			for (int j = 0; j < 3; ++j)
			{
				count[i][j] += count[i + 1][j];
			}
		}
	}

	for (int i = 0; i < n-2; ++i)
	{
		for (int j = i+1; j < n-1; ++j)
		{
			if (s[i] == s[j]) continue;

			int charIndex;
			if (s[i] != 'R' && s[j] != 'R') charIndex = 0;
			else if (s[i] != 'G' && s[j] != 'G') charIndex = 1;
			else charIndex = 2;

			result += count[j + 1][charIndex];
			int checkIndex = j + j - i;
			if (checkIndex < n && s[checkIndex] != s[i] && s[checkIndex] != s[j])
			{
				result--;
			}
		}
	}
	
	cout << result;*/
	
	//E

	//F
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<ll> dp(n,0);
	dp[0] = 0;
	vector<ll> prefix(n);
	prefix[0] = a[0];
	for (int i = 2; i < n; i += 2) {
		prefix[i] = prefix[i - 2] + a[i];
	}
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		}
		else {
			dp[i] = i == 1 ? a[i] : a[i] + dp[i - 2];
			dp[i] = max(dp[i], prefix[i - 1]);
		}
	}
	cout << dp[n-1];
	
	
}


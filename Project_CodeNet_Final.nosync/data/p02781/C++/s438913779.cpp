#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back


int bexp(int a, int b)
{
	int res = 1;

	while (b)
	{
		if (b & 1) res = (res * a);

		a = (a * a); 
		b >>= 1;
	}
	return res;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

#define N 100010
#define MOD 1000000007

int ncr(int n, int r)
{
	if (n < r)
		return 0;
	else if (r == 0)
		return 1;
	else if (r == 1)
		return n;
	else if (r == 2)
		return (n * (n - 1)) / 2;
	else
		return (n * (n - 1) * (n - 2)) / 6;
}

string s;
int r, n;

int solve(int m, int r)
{
	int ans = ncr(m - 1, r - 1) * bexp(9, r - 1) * (s[0] - '0' - 1) + ncr(m - 1, r) * bexp(9, r);
	// cout << ans << "\n";
	
	int p = 1;
	int i = 0;
	for (i = 0; i < r - 1; ++i)
	{
		while (p < n && s[p] == '0')
			p++;

		if (p == n)
			break;
		ans += ncr(n - p - 1, r - i - 2) * bexp(9, r - i - 2) * (s[p] - '0' - 1) + ncr(n - p - 1, r - i - 1) * bexp(9, r - i - 1);
		// cout << ans << "\n";
		p++;
	}
	if (i == r - 1)
		ans++;
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> s >> r;
	
	n = s.size();

	cout << solve(n, r);
	return 0;
}
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

#define N 500010
#define MOD 1000000007

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	string s;
	cin >> s;

	if (s[0] == s[1] && s[1] == s[2])
		cout << "No\n";
	else
		cout << "Yes\n";
	return 0;
}
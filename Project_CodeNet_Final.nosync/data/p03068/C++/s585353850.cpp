#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 998244353;
ll a[310], dp[90010], sum, ext, ans, dp2[90010];
int n, k;
string s;


ll pow(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2)
	{
		return pow(x, y - 1) * x % mod;
	}
	else
	{
		ll yyy = pow(x, y / 2);
		return yyy * yyy % mod;
	}
}

ll div(ll x)
{
	return pow(x, mod - 2);
}



int main(void)
{
	cin >> n >> s >> k;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == s[k - 1])
		{
			cout << s[i];
		}
		else
		{
			cout << '*';
		}
	}
	cout << endl;
	cin >> n;
}

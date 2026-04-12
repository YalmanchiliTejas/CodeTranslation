#include <bits/stdc++.h>
#define N 10000
#define pb push_back
#define fi first
#define se second
#define si size()
#define ll unsigned long long
#define mp make_pair
#define iter ::iterator
#define all(v) v.begin(), v.end()
#define pp pop_back
#define mapiter map<int, int>::iterator
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forn1(i, n) for(int i = 1; i <= n; ++i)
#define forr(i, n)	for(int i = n - 1; i >= 0; --i)
#define forr1(i, n)	for(int i = n; i >= 1; --i)
#define form(l, r, i)	for(int i = l; i <= r; ++i)
#define forv(r, l, i)	for(int i = r; i >= l; --i)
#define r0 return 0
#define barnarnar ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lld long double
#define elif else if
 
const int inf = 1e9 + 7;
const lld EPS = 0.00000001;
const ll modw = 1e9 + 7;
 
using namespace std;

int main()
{
	barnarnar
	string a;
	cin >> a;
	int d;
	cin >> d;
	vector<vector<ll> > dp(d, vector<ll>(2)); // dp[sum][is_smaller] - 'sum' - sum of digits we chosen and 'is_smaller' then k
	int k = a.si;
	dp[0][0] = 1;
	for(int len = 0; len < k; len++) // len of cur number
	{
		vector<vector<ll> > new_dp(d, vector<ll>(2));
		for(int sum = 0; sum < d; sum++)
		{
			for(bool sm : {false, true})
			{
				for(int digit = 0; digit <= 9; digit++)
				{
					if(digit > a[len] - '0' && !sm)	break;
					new_dp[(sum + digit) % d][sm || (digit < a[len] - '0')] += dp[sum][sm];
					new_dp[(sum + digit) % d][sm || (digit < a[len] - '0')] %= modw;
				}
			}
		}
		dp = new_dp;
	}
	ll ans = (dp[0][0] + dp[0][1]) % modw;
	ans--;
	if(ans == -1)	ans = modw - 1;
	cout << ans;
	return 0;
}
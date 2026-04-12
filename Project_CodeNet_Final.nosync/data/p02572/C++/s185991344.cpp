#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

ll n;
ll tsum = 0, total = 0;
ll MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<ll> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		tsum = (tsum + nums[i]) % MOD;
	}
	for (int i = 0; i < n; i++)
	{
		tsum -= nums[i];
		if (tsum < 0)
			tsum += MOD;
		total = (total + tsum * nums[i]) % MOD;
	}
	cout << total;
}
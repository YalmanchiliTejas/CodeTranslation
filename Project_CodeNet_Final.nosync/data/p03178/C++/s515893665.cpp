#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string.h>
#include <map>
#include <stack>
#include <iomanip>
#include <chrono>
#include <random>
#include <math.h>
#include <time.h>
#include <assert.h>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) x.begin(),x.end() 
#define PII pair <ll,ll>
#define N 100005
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;

ll dp[N][105];
ll func(int c, int sum, int D)
{
	if(c == 0)
		return (sum % D == 0);
	if(dp[c][sum] != -1)
		return dp[c][sum];
	ll res = 0;
	for (int i = 0; i <= 9; ++i)
	{
		res += func(c - 1, (sum + i) % D, D);
		res %= MOD;
	}
	return dp[c][sum] = res;
}
ll solve(string s, int D)
{
	int c;
	ll res = 0, sum = 0, d;
	c = (int) s.size();
	for (int i = 0; i < c; ++i)
	{
		d = s[i] - '0';
		for (int digit = 0; digit < d; ++digit)
		{
			res += func(c - i - 1, (sum + digit) % D, D);
			res %= MOD;
		}
		sum = (sum + d) % D;
	}

	if(sum % D == 0)
		res++;
	return ((res - 1) + MOD) % MOD;
}
int main()
{
	string s;
	int d;
	cin >> s >> d;
	memset(dp, -1, sizeof(dp));
	cout << solve(s, d);
}


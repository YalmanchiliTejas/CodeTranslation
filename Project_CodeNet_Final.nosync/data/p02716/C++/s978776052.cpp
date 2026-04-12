#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set> 
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <iomanip>
using namespace std;
#define assem99 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define ld long double
#define ii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<ii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define F first
#define S second
#define sz(a) (int)(a).size()
#define ReadFile freopen("input.txt","r",stdin)
#define WriteFile freopen("output.txt","w",stdout)
int x[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int y[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
const int MOD = 1e9 + 7, N = 2e5 + 5;
const double pi = acos(-1);

ll n, arr[N], dp[N][3];

ll solve(int id, int taken, int skipped)
{
	if (id >= n) return (taken == n / 2) ? 0 : -1e18;
	if (dp[id][skipped] != -1) return dp[id][skipped];
	ll ans = -1e18;
	if (skipped < 2) ans = max(ans, solve(id + 1, taken, skipped + 1));
	ans = max(ans, solve(id + 2, taken + 1, skipped) + arr[id]);
	return dp[id][skipped] = ans;
}

int main()
{ 
	assem99;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	rep(i, 0, n) cin >> arr[i];
	cout << solve(0, 0, 0);

	return 0;
}

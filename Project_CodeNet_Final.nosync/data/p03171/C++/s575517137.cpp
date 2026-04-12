#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef double ld;

int main()
{
	fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vll arr(n);
	vector<vll> dp(n, vll(n, 0));

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = n-1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (i == j)
			{
				dp[i][j] = arr[i];
			}
			else
			{
				dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
			}
		}
	}

	cout << dp[0][n - 1];

	return 0;

}
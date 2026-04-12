#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int
ll n;
ll arr[10000];
ll dp[10000][10000];
ll solve(int i, int j)
{
	if (i == j)
		return arr[i];

	if (j == i + 1)
		return max(arr[i], arr[j]);


	if (dp[i][j] != -1)
		return dp[i][j];

	ll ans1 = arr[i] + min(solve(i + 2, j), solve(i + 1, j - 1));
	ll ans2 = arr[j] + min(solve(i, j - 2), solve(i + 1, j - 1));

	return  dp[i][j] = max(ans1, ans2);

}
int main() {

	cin >> n;
	ll sum = 0;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	//cout << sum << endl;

	ll X = solve(0, n - 1);
	ll Y = sum - X;
	//cout << X << " " << Y << endl;

	cout << X - Y;

	return 0;
}
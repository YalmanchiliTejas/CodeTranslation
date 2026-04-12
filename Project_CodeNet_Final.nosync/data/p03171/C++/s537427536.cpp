#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll arr[3005], dp[3005][3005];
ll solve(bool turn, int begin, int end, ll sum)
{
	if (begin == end)
		return arr[begin];
	if (dp[begin][end])
		return dp[begin][end];
	return dp[begin][end] = sum - min(solve(!turn, begin + 1, end, sum - arr[begin]), solve(!turn, begin, end - 1, sum - arr[end]));
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	cout << 2 * solve(0, 0, n - 1, sum) - sum << '\n';
	return 0;
}
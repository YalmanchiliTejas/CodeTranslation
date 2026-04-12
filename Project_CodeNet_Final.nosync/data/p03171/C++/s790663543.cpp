#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll memo[3005][3005];

ll sol(ll arr[], int i, int j)
{
	if (i == j)
		return arr[i];
	if (i + 1 == j)
		return max(arr[i], arr[j]);
	if (memo[i][j] == 0)
	{
		ll start = arr[i] + min(sol(arr, i + 2, j),
								sol(arr, i + 1, j - 1));
		ll end = arr[j] + min(sol(arr, i + 1, j - 1),
						sol(arr, i, j - 2));
		memo[i][j] = max(start, end);
	}
	return memo[i][j];
}
int main()
{
	int n; cin >> n;
	ll arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	ll sum = 0;
	for(int i=0; i<n; i++) sum += arr[i];
	ll ans = sol(arr, 0, n-1);
	cout << 2 * ans - sum << endl;
	return 0;
}
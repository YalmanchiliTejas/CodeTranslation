#include <bits/stdc++.h>

using namespace std;

#define int 		long long
#define endl		"\n"
#define mod			1000000007
#define inf			1e12
#define IOS			ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

vector<int> a(3000);
vector<vector<int>> mem(3000, vector<int> (3000, -1));

int dp(int l, int r) {
	if (l == r)
		return a[l];

	if (l + 1 == r)
		return llabs(a[l] - a[r]);

	if (mem[l][r] != -1)
		return mem[l][r];


	int left, right, ans;
	left = min(a[l] - a[l + 1] + dp(l + 2, r), a[l] - a[r] + dp(l + 1, r - 1));

	right = min(a[r] - a[l] + dp(l + 1, r - 1), a[r] - a[r - 1] + dp(l, r - 2));

	ans = max(left, right);

	return mem[l][r] = ans;
}

int32_t main() {

	IOS;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << dp(0, n - 1);

	return 0;
}